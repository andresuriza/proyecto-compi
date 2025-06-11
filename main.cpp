#include <QApplication>
#include <QMainWindow>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QLabel>
#include <QTextCursor>
#include <QTextBlock>
#include <QTextCharFormat>
#include <QList>
#include <QRegularExpression>
#include <QListWidget>
#include <qtermwidget5/qtermwidget.h>
#include <QDebug>

class IDEWindow : public QMainWindow {
    Q_OBJECT

public:
    IDEWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        editor = new QPlainTextEdit();
        editor->setFont(QFont("Courier", 12));
        editor->setLineWrapMode(QPlainTextEdit::NoWrap);

        terminal = new QTermWidget();
        terminal->setScrollBarPosition(QTermWidget::ScrollBarRight);

        errorPanel = new QListWidget();
        errorPanel->setStyleSheet("background-color: #fee; color: #900;");

        openBtn = new QPushButton("Abrir");
        saveBtn = new QPushButton("Guardar");
        compileBtn = new QPushButton("Compilar");

        auto buttonLayout = new QHBoxLayout();
        buttonLayout->addWidget(openBtn);
        buttonLayout->addWidget(saveBtn);
        buttonLayout->addWidget(compileBtn);

        auto mainLayout = new QVBoxLayout();
        mainLayout->addLayout(buttonLayout);
        mainLayout->addWidget(new QLabel("Editor de Código"));
        mainLayout->addWidget(editor, 3);
        mainLayout->addWidget(new QLabel("Terminal Embebida"));
        mainLayout->addWidget(terminal, 2);
        mainLayout->addWidget(new QLabel("Errores de Compilación"));
        mainLayout->addWidget(errorPanel);

        QWidget *central = new QWidget();
        central->setLayout(mainLayout);
        setCentralWidget(central);

        connect(openBtn, &QPushButton::clicked, this, &IDEWindow::openFile);
        connect(saveBtn, &QPushButton::clicked, this, &IDEWindow::saveFile);
        connect(compileBtn, &QPushButton::clicked, this, &IDEWindow::compileCode);

        setWindowTitle("VGraph IDE");
        resize(1000, 700);

        terminal->setShellProgram("/bin/bash"); // ✅ Forzar bash explícitamente
terminal->startShellProgram();
connect(terminal, &QTermWidget::receivedData, this, &IDEWindow::handleTerminalOutput);


    }

private slots:
    void openFile() {
        QString path = QFileDialog::getOpenFileName(this, "Abrir archivo", "", "Archivos VGraph (*.vg *.txt);;Todos (*)");
        if (!path.isEmpty()) {
            QFile file(path);
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);
                editor->setPlainText(in.readAll());
            }
        }
    }

    void saveFile() {
        QString path = QFileDialog::getSaveFileName(this, "Guardar archivo", "", "Archivos VGraph (*.vg *.txt);;Todos (*)");
        if (!path.isEmpty()) {
            QFile file(path);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << editor->toPlainText();
            }
        }
    }

    void clearErrorHighlights() {
        QTextCursor cursor(editor->document());
        cursor.select(QTextCursor::Document);
        QTextCharFormat fmt;
        fmt.setUnderlineStyle(QTextCharFormat::NoUnderline);
        cursor.setCharFormat(fmt);
    }

    void highlightLine(int lineNumber, const QString &message) {
        QTextBlock block = editor->document()->findBlockByNumber(lineNumber);
        if (block.isValid()) {
            QTextCursor cursor(block);
            cursor.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);
            QTextCharFormat fmt;
            fmt.setUnderlineStyle(QTextCharFormat::WaveUnderline);
            fmt.setUnderlineColor(Qt::red);
            cursor.setCharFormat(fmt);
        }
        errorPanel->addItem("Línea " + QString::number(lineNumber + 1) + ": " + message);
        terminal->sendText("echo '[Error línea " + QString::number(lineNumber + 1) + "] " + message + "'\n");
    }

    bool checkSyntax() {
        clearErrorHighlights();
        errorPanel->clear();

        QString text = editor->toPlainText();
        QStringList lines = text.split('\n');
        bool valid = true;

        QRegularExpression validPatterns[] = {
    // Declaración de variables
    QRegularExpression("^\\s*\\((int|color)\\)\\s+[a-z][a-zA-Z0-9]*(\\s*,\\s*[a-z][a-zA-Z0-9]*)*\\s*;\\s*$"),

    // Asignaciones
QRegularExpression("^\\s*[a-z][a-zA-Z0-9]*\\s*=\\s*.+;\\s*(#.*)?$"),

    // Instrucciones draw
    QRegularExpression("^\\s*draw\\s+(line|circle|rect|pixel|tree)\\s*\\(.*\\)\\s*;\\s*$"),

    // setcolor y wait
    QRegularExpression("^\\s*setcolor\\s*\\(.*\\)\\s*;\\s*$"),
    QRegularExpression("^\\s*wait\\s*\\([^\\)]+\\)\\s*;\\s*(#.*)?$"),

    // Estructuras de control
    QRegularExpression("^\\s*frame\\s*\\{\\s*$"),
    QRegularExpression("^\\s*loop\\s*\\(.*\\)\\s*\\{\\s*$"),
    QRegularExpression("^\\s*if\\s*\\([^\\)]+\\)\\s*\\{.*\\}\\s*(#.*)?$"),             // ✅ acepta condiciones complejas
    QRegularExpression("^\\s*else\\s+if\\s*\\([^\\)]+\\)\\s*\\{.*\\}\\s*(#.*)?$"),     // ✅ acepta condiciones complejas
    QRegularExpression("^\\s*else\\s*\\{.*\\}\\s*(#.*)?$"),
    QRegularExpression("^\\s*end\\s*$"),
    QRegularExpression("^\\s*\\}\\s*$"),

    // Comentarios y líneas vacías
    QRegularExpression("^\\s*#.*$"),
    QRegularExpression("^\\s*$")
};




        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines[i].trimmed();
            if (line.isEmpty() || line.startsWith("#")) continue;

            bool matched = false;
            for (const auto &pattern : validPatterns) {
                if (pattern.match(line).hasMatch()) {
                    matched = true;
                    break;
                }
            }

            if (!matched) {
                highlightLine(i, "Línea no válida según la gramática.");
                valid = false;
            }
        }

        return valid;
    }

    void compileCode() {
    bool passed = checkSyntax();
    if (!passed) {
        QMessageBox::warning(this, "Advertencia", "Se detectaron errores de sintaxis, pero se continuará con la compilación.");
    }

    QFile file("test.vg");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << editor->toPlainText();
        file.close();

        // 🔁 Captura stdout y stderr
        QString command = QString(
            "bash -c 'echo Guardado como test.vg && make 2>&1 && echo Compilación exitosa && ./vgraph < test.vg || echo Error en compilación'\n"
        );
        terminal->sendText(command);
    } else {
        QMessageBox::warning(this, "Error", "No se pudo guardar el archivo test.vg");
    }
}

void handleTerminalOutput(const QString &text) {
    terminalBuffer += text;

    int newlineIndex;
    while ((newlineIndex = terminalBuffer.indexOf('\n')) != -1) {
        QString rawLine = terminalBuffer.left(newlineIndex);
        terminalBuffer = terminalBuffer.mid(newlineIndex + 1);

        // 🔤 Corrige tildes mal interpretadas
        QString line = QString::fromLocal8Bit(rawLine.toUtf8()).trimmed();

        qDebug() << "Línea recibida del compilador:" << line;

        QRegularExpression regexWithLine("Error\\s+de\\s+sintaxis\\s+en\\s+l[ií]nea\\s+(\\d+)[^:]*:\\s*(.*)", QRegularExpression::CaseInsensitiveOption);
        QRegularExpression regexGeneric("syntax error", QRegularExpression::CaseInsensitiveOption);

        QRegularExpressionMatch match = regexWithLine.match(line);
        if (match.hasMatch()) {
            int lineNum = match.captured(1).toInt() - 1;
            QString message = match.captured(2);
            highlightLine(lineNum, "Error de compilación: " + message);
        } else if (regexGeneric.match(line).hasMatch()) {
            errorPanel->addItem("❌ Error de compilación: syntax error (sin línea específica)");
        }
    }
}







private:
    QPlainTextEdit *editor;
    QTermWidget *terminal;
    QPushButton *openBtn;
    QPushButton *saveBtn;
    QPushButton *compileBtn;
    QListWidget *errorPanel;
    QString terminalBuffer;

};

#include "main.moc"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    IDEWindow window;
    window.show();
    return app.exec();
}
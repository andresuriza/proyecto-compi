#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QLabel>             // <-- esta línea faltaba
#include <qtermwidget5/qtermwidget.h>
#include <QTextCursor>
#include <QTextBlock>
#include <QTextCharFormat>
#include <QList>
#include <QRegularExpression>


class IDEWindow : public QMainWindow {
    Q_OBJECT

public:
    IDEWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        // Editor de texto
        editor = new QTextEdit();
        editor->setFont(QFont("Courier", 12));

        // Terminal embebida
        terminal = new QTermWidget();
        terminal->setScrollBarPosition(QTermWidget::ScrollBarRight);

        // Botones
        openBtn = new QPushButton("Abrir");
        saveBtn = new QPushButton("Guardar");
        compileBtn = new QPushButton("Compilar");

        // Layout botones
        auto buttonLayout = new QHBoxLayout();
        buttonLayout->addWidget(openBtn);
        buttonLayout->addWidget(saveBtn);
        buttonLayout->addWidget(compileBtn);

        // Layout principal vertical
        auto mainLayout = new QVBoxLayout();
        mainLayout->addLayout(buttonLayout);
        mainLayout->addWidget(new QLabel("Editor de Código"));
        mainLayout->addWidget(editor, 3);
        mainLayout->addWidget(new QLabel("Terminal Embebida"));
        mainLayout->addWidget(terminal, 2);

        // Widget central
        QWidget *central = new QWidget();
        central->setLayout(mainLayout);
        setCentralWidget(central);

        // Conectar señales y slots
        connect(openBtn, &QPushButton::clicked, this, &IDEWindow::openFile);
        connect(saveBtn, &QPushButton::clicked, this, &IDEWindow::saveFile);
        connect(compileBtn, &QPushButton::clicked, this, &IDEWindow::compileCode);

        setWindowTitle("VGraph IDE");
        resize(1000, 700);

        // Iniciar terminal bash
        terminal->startShellProgram();
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
        fmt.setUnderlineStyle(QTextCharFormat::WaveUnderline);  // subrayado ondulado
        fmt.setUnderlineColor(Qt::red);                         // color del subrayado

        cursor.setCharFormat(fmt);
    }
    
    terminal->sendText("echo '[Error línea " + QString::number(lineNumber + 1) + "] " + message + "'\n");
}

    

    bool checkSyntax() {
    clearErrorHighlights();
    QString text = editor->toPlainText();
    QStringList lines = text.split('\n');
    bool valid = true;

    QRegularExpression validPatterns[] = {
        QRegularExpression("^\\s*(\\(int\\)|\\(color\\))\\s+[a-z][a-zA-Z0-9]{0,9}(\\s*=\\s*[^;]+)?\\s*;\\s*$"),
        QRegularExpression("^\\s*[a-z][a-zA-Z0-9]{0,9}\\s*=\\s*[^;]+\\s*;\\s*$"), // asignaciones simples
        QRegularExpression("^\\s*draw\\s+(line|circle|rect|pixel)\\s*\\([^\\)]*\\)\\s*;\\s*$"),
        QRegularExpression("^\\s*setcolor\\s*\\([^\\)]+\\)\\s*;\\s*$"),
        QRegularExpression("^\\s*frame\\s*\\{\\s*$"),
        QRegularExpression("^\\s*loop\\s*\\([^\\)]+\\)\\s*\\{\\s*$"),
        QRegularExpression("^\\s*if\\s*\\([^\\)]+\\)\\s*\\{\\s*$"),
        QRegularExpression("^\\s*else\\s*\\{\\s*$"),
        QRegularExpression("^\\s*wait\\s*\\([^\\)]+\\)\\s*;\\s*$"),
        QRegularExpression("^\\s*end\\s*$"),
        QRegularExpression("^\\s*\\}\\s*$"), // cierre de bloque
        QRegularExpression("^\\s*#.*$"),     // comentario
        QRegularExpression("^\\s*$")         // línea vacía
    };

    for (int i = 0; i < lines.size(); ++i) {
        QString line = lines[i].trimmed();

        // Saltar líneas vacías y comentarios
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
    if (!checkSyntax()) {
        QMessageBox::warning(this, "Errores de Sintaxis", "Se encontraron errores en el código. Revise las líneas marcadas.");
        return;
    }

    QFile file("test.vg");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << editor->toPlainText();
        file.close();

        QString command = QString(
            "bash -c 'echo Guardado como test.vg && make && echo Compilación exitosa && ./vgraph < test.vg || echo Error en compilación'\n"
        );

        terminal->sendText(command);
    } else {
        QMessageBox::warning(this, "Error", "No se pudo guardar el archivo test.vg");
    }
}

private:
    QTextEdit *editor;
    QTermWidget *terminal;
    QPushButton *openBtn;
    QPushButton *saveBtn;
    QPushButton *compileBtn;
};

#include "main.moc"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    IDEWindow window;
    window.show();
    return app.exec();
}

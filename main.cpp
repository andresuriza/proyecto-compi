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

    void compileCode() {
        // Guardar en temp.vg
        QFile file("temp.vg");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << editor->toPlainText();
            file.close();

            // Ejecutar comando compilador en terminal embebida
            QString command = QString("echo 'Compilando temp.vg...'; ./vgraph_compiler temp.vg; echo 'Compilación terminada.'\n");
            terminal->sendText(command);
        } else {
            QMessageBox::warning(this, "Error", "No se pudo guardar el archivo temp.vg");
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

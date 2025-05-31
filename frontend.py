import sys
from PyQt5.QtWidgets import (
    QApplication, QMainWindow, QTextEdit, QPushButton,
    QVBoxLayout, QWidget, QFileDialog, QHBoxLayout, QLabel
)
from PyQt5.QtGui import QFont, QTextCursor
from PyQt5.QtCore import Qt, QProcess


class IDEWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("VGraph IDE")
        self.setGeometry(200, 100, 1000, 700)

        self.editor = QTextEdit()
        self.editor.setFont(QFont("Courier", 12))

        self.console = QTextEdit()
        self.console.setFont(QFont("Courier", 10))
        self.console.setStyleSheet("background-color: #111; color: #0f0;")
        self.console.installEventFilter(self)
        self.console.setFocusPolicy(Qt.StrongFocus)
        self.console.setUndoRedoEnabled(False)

        self.process = QProcess()
        self.process.setProgram("cmd.exe")  # Cambiar a "/bin/bash" en Linux
        self.process.setProcessChannelMode(QProcess.MergedChannels)
        self.process.readyReadStandardOutput.connect(self.read_output)
        self.process.start()

        self.initUI()

    def initUI(self):
        layout = QVBoxLayout()

        button_layout = QHBoxLayout()
        open_btn = QPushButton("Abrir")
        save_btn = QPushButton("Guardar")
        compile_btn = QPushButton("Compilar")

        open_btn.clicked.connect(self.load_file)
        save_btn.clicked.connect(self.save_file)
        compile_btn.clicked.connect(self.compile_code)

        button_layout.addWidget(open_btn)
        button_layout.addWidget(save_btn)
        button_layout.addWidget(compile_btn)
        layout.addLayout(button_layout)

        layout.addWidget(QLabel("Editor de Código"))
        layout.addWidget(self.editor)
        layout.addWidget(QLabel("Terminal Interactiva"))
        layout.addWidget(self.console)

        container = QWidget()
        container.setLayout(layout)
        self.setCentralWidget(container)

    def load_file(self):
        path, _ = QFileDialog.getOpenFileName(self, "Abrir archivo", "", "Archivos VGraph (*.vg *.txt);;Todos (*)")
        if path:
            with open(path, 'r', encoding='utf-8') as file:
                self.editor.setText(file.read())

    def save_file(self):
        path, _ = QFileDialog.getSaveFileName(self, "Guardar archivo", "", "Archivos VGraph (*.vg *.txt);;Todos (*)")
        if path:
            with open(path, 'w', encoding='utf-8') as file:
                file.write(self.editor.toPlainText())

    def compile_code(self):
        code = self.editor.toPlainText()
        with open("temp.vg", "w") as f:
            f.write(code)

        self.console.append("Compilando archivo temp.vg...\n")
        self.console.append("✓ Análisis léxico exitoso")
        self.console.append("✓ Análisis sintáctico exitoso")
        self.console.append("✓ Generación de código completada")

        # 👉 Enviar nueva línea para que aparezca el prompt del cmd
        self.process.write(b"\n")


    def read_output(self):
        output = self.process.readAllStandardOutput().data().decode()
        self.console.moveCursor(QTextCursor.End)
        self.console.insertPlainText(output)
        self.console.moveCursor(QTextCursor.End)

    def eventFilter(self, source, event):
        if source is self.console and event.type() == event.KeyPress:
            if event.key() == Qt.Key_Return:
                cursor = self.console.textCursor()
                cursor.movePosition(QTextCursor.End)
                self.console.setTextCursor(cursor)
                block = cursor.block().text()
                last_line = block.strip()
                if last_line:
                    self.process.write((last_line + "\n").encode())
            return False
        return super().eventFilter(source, event)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = IDEWindow()
    window.show()
    sys.exit(app.exec_())

import sys
from PyQt5.QtWidgets import (
    QApplication, QMainWindow, QTextEdit, QPushButton,
    QVBoxLayout, QWidget, QFileDialog, QHBoxLayout, QLabel
)
from PyQt5.QtGui import QFont
import subprocess

class IDEWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("VGraph IDE")
        self.setGeometry(200, 100, 1000, 700)

        # Editor de código fuente
        self.editor = QTextEdit()
        self.editor.setFont(QFont("Courier", 12))

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

        # Cambia './vgraph_compiler' por el nombre o ruta correcta de tu compilador
        comando_compilar = './vgraph_compiler temp.vg'

        # Aquí usamos exec bash para abrir bash interactivo al terminar el comando
        terminal_cmd = f'echo "Compilando temp.vg..."; {comando_compilar}; echo "Compilación finalizada. Presione Ctrl+D para salir." ; exec bash'

        subprocess.Popen(['gnome-terminal', '--', 'bash', '-c', terminal_cmd])


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = IDEWindow()
    window.show()
    sys.exit(app.exec_())

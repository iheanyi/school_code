
import sys
#import PyQt4
from PyQt4.QtCore import *
from PyQt4.QtGui import *

class MainWindow(QMainWindow):
	def __init__(self, parent=None):
		super(MainWindow, self).__init__(parent)
		self.parseTextEdit = QTextEdit()
		self.parseTextLabel = QLabel()
		self.parseButton = QPushButton("Parse")

		self.filename = None

		self.mirroredvertically = False
		self.mirroredhorizontally = False


		self.setWindowTitle("Email Parser")
		
		#self.addActions(self.filemenu, (self.fileMenuAction))

		self.resultLabel = QLabel()
		self.resultText = QTextEdit()
		self.domainEdit = QLineEdit()

		exitaction = QAction('&Exit', self)        
		exitaction.setShortcut('Ctrl+Q')
		exitaction.setStatusTip('Exit application')
		exitaction.triggered.connect(qApp.quit)

		self.statusBar()

		menubar = self.menuBar()
		fileMenu = menubar.addMenu('&File')
		fileMenu.addAction(exitaction)
        
		self.setGeometry(300, 300, 300, 200)
		self.show()


def main():

	app = QApplication(sys.argv)
	form = MainWindow()
	#form.show()
	sys.exit(app.exec_())

if __name__ == '__main__':
	main()
mainwindow tob
void setupUi(QMainWindow *mainwindow_tob)
{
    if (mainwindow_tob->objectName().isEmpty())
        mainwindow_tob->setObjectName(QString::fromUtf8("mainwindow_tob"));
    mainwindow_tob->resize(450, 800);
    mainwindow_tob->setStyleSheet("background-color: #ffffff;");

    centralwidget = new QWidget(mainwindow_tob);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));

    QVBoxLayout *layout = new QVBoxLayout(centralwidget);

    // title
    QLabel *title = new QLabel("Main Window", centralwidget);
    QFont titleFont;
    titleFont.setPointSize(18);
    titleFont.setBold(true);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("color: #444444;");
    layout->addWidget(title);

    // rolling area
    QScrollArea *scrollArea = new QScrollArea(centralwidget);
    scrollArea->setWidgetResizable(true);
    scrollArea->setStyleSheet(
        "QScrollArea { border: 1px solid #dddddd; border-radius: 5px; }"
        "QScrollBar:vertical { background: #eaeaea; width: 10px; }"
        "QScrollBar::handle:vertical { background: #cccccc; border-radius: 5px; }");
    layout->addWidget(scrollArea);

    QWidget *scrollContent = new QWidget();
    scrollArea->setWidget(scrollContent);

    mainwindow_tob->setCentralWidget(centralwidget);

    // status bar
    QStatusBar *statusBar = new QStatusBar(mainwindow_tob);
    statusBar->setStyleSheet(
        "QStatusBar { background-color: #f0f0f0; border-top: 1px solid #dddddd; }");
    mainwindow_tob->setStatusBar(statusBar);
}
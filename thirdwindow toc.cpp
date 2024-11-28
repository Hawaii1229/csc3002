thirdwindow toc
void setupUi(QMainWindow *thirdwindow_toc)
{
    if (thirdwindow_toc->objectName().isEmpty())
        thirdwindow_toc->setObjectName(QString::fromUtf8("thirdwindow_toc"));
    thirdwindow_toc->resize(770, 969);
    thirdwindow_toc->setStyleSheet("background-color: #ffffff;");

    centralwidget = new QWidget(thirdwindow_toc);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));

    QVBoxLayout *mainLayout = new QVBoxLayout(centralwidget);

    // table set up
    bill = new QTableWidget(centralwidget);
    bill->setStyleSheet(
        "QTableWidget { border: 1px solid #dddddd; border-radius: 5px; background: #fafafa; }");
    mainLayout->addWidget(bill);

    // QR code display
    QRcode = new QGraphicsView(centralwidget);
    QRcode->setStyleSheet("border: 2px dashed #cccccc;");
    QRcode->setFixedSize(450, 450);
    mainLayout->addWidget(QRcode);

    pushButton = new QPushButton("Confirm", centralwidget);
    pushButton->setStyleSheet(
        "QPushButton { background-color: #0078d4; color: white; font-size: 16px; border-radius: 5px; }"
        "QPushButton:hover { background-color: #005bb5; }");
    mainLayout->addWidget(pushButton);

    thirdwindow_toc->setCentralWidget(centralwidget);
}

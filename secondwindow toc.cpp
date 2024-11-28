secondwindow toc 
void setupUi(QMainWindow *secondwindow_toc)
{
    if (secondwindow_toc->objectName().isEmpty())
        secondwindow_toc->setObjectName(QString::fromUtf8("secondwindow_toc"));
    secondwindow_toc->resize(450, 800);
    secondwindow_toc->setStyleSheet("background-color: #fcfcfc;");

    centralwidget = new QWidget(secondwindow_toc);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));

    QVBoxLayout *layout = new QVBoxLayout(centralwidget);

    // rolling area
    m_scrollArea = new QScrollArea(centralwidget);
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setStyleSheet(
        "QScrollArea { border: none; }"
        "QScrollBar:vertical { background: #f0f0f0; width: 10px; }");
    scrollAreaWidgetContents = new QWidget();
    m_scrollArea->setWidget(scrollAreaWidgetContents);
    layout->addWidget(m_scrollArea);

    QHBoxLayout *paymentLayout = new QHBoxLayout();
    label = new QLabel("Total:", centralwidget);
    label->setStyleSheet("font-size: 20px; color: #222222;");
    paymentLayout->addWidget(label);

    payment = new QLCDNumber(centralwidget);
    payment->setStyleSheet(
        "QLCDNumber { border: 2px solid #aaaaaa; border-radius: 5px; background: #f0f0f0; }");
    paymentLayout->addWidget(payment);

    layout->addLayout(paymentLayout);

    pushButton = new QPushButton("Pay", centralwidget);
    pushButton->setStyleSheet(
        "QPushButton { background-color: #4caf50; color: white; font-size: 18px; border-radius: 5px; }"
        "QPushButton:hover { background-color: #45a049; }");
    layout->addWidget(pushButton);

    secondwindow_toc->setCentralWidget(centralwidget);
}
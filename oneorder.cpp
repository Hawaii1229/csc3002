oneorder
void setupUi(QWidget *oneOrder)
{
    if (oneOrder->objectName().isEmpty())
        oneOrder->setObjectName(QString::fromUtf8("oneOrder"));
    oneOrder->resize(400, 300);
    oneOrder->setMinimumSize(QSize(400, 300));
    oneOrder->setMaximumSize(QSize(400, 300));
    oneOrder->setStyleSheet("background-color: #fefefe;");

    // display order content
    showorder = new QTextBrowser(oneOrder);
    showorder->setObjectName(QString::fromUtf8("showorder"));
    showorder->setGeometry(QRect(20, 20, 300, 240));
    showorder->setStyleSheet(
        "QTextBrowser { border: 2px solid #dcdcdc; border-radius: 8px; padding: 10px; background: #ffffff; "
        "font-size: 14px; color: #333333; }");

    // finish botton
    complete = new QPushButton(oneOrder);
    complete->setObjectName(QString::fromUtf8("complete"));
    complete->setGeometry(QRect(330, 130, 60, 40));
    complete->setStyleSheet(
        "QPushButton { background-color: #0078d4; color: white; font-size: 14px; border-radius: 6px; }"
        "QPushButton:hover { background-color: #005bb5; }");

    retranslateUi(oneOrder);
    QMetaObject::connectSlotsByName(oneOrder);
}

void retranslateUi(QWidget *oneOrder)
{
    oneOrder->setWindowTitle(QApplication::translate("oneOrder", "Order Details", nullptr));
    complete->setText(QApplication::translate("oneOrder", "Finish", nullptr));
}
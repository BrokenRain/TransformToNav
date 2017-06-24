#pragma once

#if _MSC_VER >= 1600  
#pragma execution_character_set("utf-8")  
#endif

#include <QtWidgets/QWidget>
#include "ui_TransformToNav.h"
#include "TxtToNav.h"
#include "CsvToNav.h"

using namespace std;

class Nav : public QWidget
{
    Q_OBJECT

private slots:
	void on_pushButton_selcet_clicked();
	void on_pushButton_save_clicked();
	void on_pushButton_Transform_clicked();
	
public:
    Nav(QWidget *parent = Q_NULLPTR);

private:
    Ui::TransformToNavClass ui;

	TxtToNav txt_Nav;
	CsvToNav csv_Nav;

	int i_filetype;			//1:txt  2:csv
	QString qs_filename;
	QString qs_savepath;
};

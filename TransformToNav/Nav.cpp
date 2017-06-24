#include "Nav.h"
#include <QFileDialog>
#include <QMessageBox>

Nav::Nav(QWidget *parent)
{
	ui.setupUi(this);

	i_filetype = 0;
	qs_filename = "";
	qs_savepath = "";
}

void Nav::on_pushButton_selcet_clicked()
{
	qs_filename = QFileDialog::getOpenFileName(this, "请选择转换文件", ".", "TEXT Files(*.txt);;csv File(*.csv)", 0, 0);
	if (qs_filename == "")
	{
		return;
	}

	ui.lineEdit_filename->setText(qs_filename);
}

void Nav::on_pushButton_save_clicked()
{
	qs_savepath = QFileDialog::getExistingDirectory(this, "请选择保存位置", ".");

	if (qs_savepath == "")
	{
		return;
	}

	int length1 = qs_filename.lastIndexOf("/");
	int length2 = qs_filename.lastIndexOf(".");

	qs_savepath += qs_filename.mid(length1, length2 - length1) + ".nav";

	ui.lineEdit_save->setText(qs_savepath);
}

void Nav::on_pushButton_Transform_clicked()
{
	if (qs_filename == "")
	{
		QMessageBox::information(NULL, "提示", "请选择需转换文件！", QMessageBox::Yes, 0);
		return;
	}
	
	if (qs_savepath == "")
	{
		QMessageBox::information(NULL, "提示", "请选择保存路径！", QMessageBox::Yes, 0);
		return;
	}
	

	int length = qs_filename.lastIndexOf(".");
	QString qs_suff = qs_filename.mid(length + 1);

	if (qs_suff == "txt")
	{
		txt_Nav.SetTransFormFileName(qs_filename.toLocal8Bit().toStdString());
		if (!txt_Nav.ReadShot())
		{
			QMessageBox::information(NULL, "提示", "转换失败,请检查转换文件格式！", QMessageBox::Yes, QMessageBox::Yes);
			return;
		}
		
		txt_Nav.SetSaveFileName(qs_savepath.toLocal8Bit().toStdString());

		if (txt_Nav.TransForm())
		{
			QMessageBox::information(NULL, "提示", "转换失败,请检查转换文件格式！", QMessageBox::Yes, QMessageBox::Yes);
			return;
		}
	}
	else
	{
		csv_Nav.SetTransFormFileName(qs_filename.toLocal8Bit().toStdString());
		if (csv_Nav.ReadShot())
		{
			QMessageBox::information(NULL, "提示", "转换失败,请检查转换文件格式！", QMessageBox::Yes, QMessageBox::Yes);
			return;
		}

		csv_Nav.SetSaveFileName(qs_savepath.toLocal8Bit().toStdString());
		if (csv_Nav.TransForm())
		{
			QMessageBox::information(NULL, "提示", "转换失败,请检查转换文件格式！", QMessageBox::Yes, QMessageBox::Yes);
			return;
		}
	}

	QMessageBox::information(NULL, "提示", "转换成功！", QMessageBox::Yes, QMessageBox::Yes);
}
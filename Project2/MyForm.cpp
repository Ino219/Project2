#include "MyForm.h"

using namespace Project2;

[STAThreadAttribute]

int main() {
	Application::Run(gcnew MyForm());
	return 0;
}

System::Void Project2::MyForm::MyForm_DragDrop(System::Object ^ sender, System::Windows::Forms::DragEventArgs ^ e)
{

	//リストとしてファイルパス取得
	array<String^>^ file = (array<String^>^)e->Data->GetData(DataFormats::FileDrop, false);
	//拡張子取得
	String^	extension = System::IO::Path::GetExtension(file[0]);
	if (extension != ".txt")return;
	//ファイル名取得
	String^ title = System::IO::Path::GetFileName(file[0]);
	String^ newName = "newName" + extension;
	//ディレクトリ名取得
	String^ directory = System::IO::Path::GetDirectoryName(file[0]);
	//パスを取得
	String^ path = System::IO::Path::GetFullPath(file[0]);
	
	//ファイル名の変更完了
	System::IO::File::Move(path, directory+"\\"+newName);

	//コピー先のフォルダを指定
	String^ folderPath = directory + "\\folder";
	//コピー先のファイル名を指定
	String^ copyTo = folderPath + "\\copy.txt";
	//ファイルのコピーを実行
	System::IO::File::Copy(directory + "\\" + newName, copyTo);

	return System::Void();
}

System::Void Project2::MyForm::MyForm_DragEnter(System::Object ^ sender, System::Windows::Forms::DragEventArgs ^ e)
{
	if (e->Data->GetDataPresent(DataFormats::FileDrop)) {
		e->Effect = DragDropEffects::All;
	}
	else {
		e->Effect = DragDropEffects::None;
	}
	return System::Void();
}

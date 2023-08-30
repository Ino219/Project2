#include "MyForm.h"

using namespace Project2;

[STAThreadAttribute]

int main() {
	Application::Run(gcnew MyForm());
	return 0;
}

System::Void Project2::MyForm::MyForm_DragDrop(System::Object ^ sender, System::Windows::Forms::DragEventArgs ^ e)
{

	//���X�g�Ƃ��ăt�@�C���p�X�擾
	array<String^>^ file = (array<String^>^)e->Data->GetData(DataFormats::FileDrop, false);
	//�g���q�擾
	String^	extension = System::IO::Path::GetExtension(file[0]);
	if (extension != ".txt")return;
	//�t�@�C�����擾
	String^ title = System::IO::Path::GetFileName(file[0]);
	String^ newName = "newName" + extension;
	//�f�B���N�g�����擾
	String^ directory = System::IO::Path::GetDirectoryName(file[0]);
	//�p�X���擾
	String^ path = System::IO::Path::GetFullPath(file[0]);
	
	//�t�@�C�����̕ύX����
	System::IO::File::Move(path, directory+"\\"+newName);

	//�R�s�[��̃t�H���_���w��
	String^ folderPath = directory + "\\folder";
	//�R�s�[��̃t�@�C�������w��
	String^ copyTo = folderPath + "\\copy.txt";
	//�t�@�C���̃R�s�[�����s
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

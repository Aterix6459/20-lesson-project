#include <iostream>
#include <string>
using namespace std;

class package {
private:
    string name;
    float version;
    float sizeMB;
    bool isInstall = false;
    string yes_or_no;
public:

    package(string name, float version, float sizeMB) {
        this->name = name;
        this->version = version;
        this->sizeMB = sizeMB;
    }
    ~package(){
        cout << "закрытие программы..." << endl;
        cout << "удаление кэша..." << endl;
        cout << "кэш полностью удалён, программа завершается...." << endl;
        cout << "программа успешно закрылась." << endl;
    }

    void print_info(){
        if(isInstall == true)
            cout << "name packet: " << name << endl\
            << "version: " << version << endl\
            << "size: " << sizeMB << "MB" << endl; 
        else{
            cout << "этот пакет не установлен." << endl;
        }
    }
    void remove(){
        cout << "вы действительно хотите удалить пакет " << name << "?(Y/n): ";
        cin >> yes_or_no;
        cout << endl;
        if(yes_or_no == "y") {
            cout << "удаление..." << endl;
            isInstall = false;
            cout << "пакет успешно удалён." << endl;
        }
        else {
            cout << "операция была прервана пользователем." << endl;
        }
    }
    void install() {
        if(isInstall == true)
            cout << "пакет уже установлен." << endl;
        else{
            cout << "установка... " << endl;
            isInstall = true;
            cout << "пакет успешно установлен." << endl;
        }

    }
};



int main(){

    package file("myPacket", 1.43, 13);
    file.print_info();
    file.install();
    file.remove();

    return 0;
}
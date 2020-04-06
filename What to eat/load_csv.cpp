#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <sstream>
using namespace std;

int randomInt(int count); /* ���˱���t��k (input an int n , return int from zero to n randomly)*/

class restaurant
{
public:
    string name;
    string place;
    string type;
    string budget;
    string address;
};

//readfile
void load_Csv(char filename[], restaurant* all_Restaurant)
{
  fstream file;
  file.open("table.csv");
  string line;
  int i = 0;
  while (getline( file, line,'\n'))  //Ū��Ū�����r��
    {
	  istringstream templine(line); // string �ഫ�� stream
	  string data;
	  getline(templine, data,','); //Ū��Ū��r��
	  all_Restaurant[i].name = data;
      getline(templine, data,','); //Ū��Ū��r��
	  all_Restaurant[i].budget = data;
	  getline(templine, data,','); //Ū��Ū��r��
	  all_Restaurant[i].type = data;
	  getline(templine, data,','); //Ū��Ū��r��
	  all_Restaurant[i].place = data;
	  getline(templine, data,','); //Ū��Ū��r��
	  all_Restaurant[i].address = data;
	  i++;
	}    
}

int main()
{   
//    string type;
//    string budget;
//    string place;
//    cout << "�п�ܷQ�n���\�U����" << "\n";
//    cout << "A1�G�t���BA2�G�ۧU�BA3�G�x���BA4�q���BA5�����BA6�䦡�BA7�馡�BA8�����BA9��L�]�p�I�ߡG���B���N�B�Q�p����) ����GA10���I�BA11�B�~�BA12����" << "\n";
//    cin >> type;
//    cout << "�п�J���\�w��" << "\n";
//    cout << "B1�]1��150�^�BB2�]151��250�^�BB3�]251��500�^�BB4�]501��infinity�^" << "\n";
//    cin  >> budget;
//    cout << "�п�J�\�U�a�I" << "\n";
//    cout << "C1�դ��BC2�s�ͫn�����BC3��������BC4�򶩸����BC5ù���ָ����BC6����������" << "\n";
//    cin >> place;
//    
//    cout << restaurant.name << "\n" << restaurant.address <<endl;
    
    restaurant all_Restaurant[1000];
    load_Csv("table.csv", all_Restaurant);
    cout << all_Restaurant[0].name;
    return 0;
}

// input an int n , return int from zero to n randomly
int randomInt(int count)
{
    random_device rd;
    
    /* ���˱���t��k */
    mt19937_64 generator( rd() );
    
    uniform_real_distribution< > dis(0 , count + 1) ;
    int x = dis(generator);
    return x;
}

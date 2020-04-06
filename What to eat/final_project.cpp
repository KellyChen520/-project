#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
using namespace std;

int randomInt(int countAvailable); /* ���˱���t��k (input an int n , return int from zero to n randomly)*/

class restaurant
{
public:
    string name;
    string place;
    string type;
    string budget;
    string address;
    int index;
};

int findAvailable(string budget , string type , string place , restaurant* all_Restaurant)
{
    int budgetWordCnt = 0;
    int typeWordCnt = 0 ;
    int placeWordCnt = 0;
    char delim[] = ",";
    string budget_cut[4] = {"", "", "", ""};
    string word;

    stringstream stream_budget(budget);
    while(getline(stream_budget, word, ','))
    {
        budget_cut[budgetWordCnt] = word;
        budgetWordCnt++;
    }

    stringstream stream_type(type);
    string type_cut[20] = {"","","","","","","","","","","","","","","","","","","",""};
    while(getline(stream_type, word, ','))
    {
        type_cut[typeWordCnt] = word;
        typeWordCnt++;
    }

    stringstream stream_place(place);
    string place_cut[6] = {"","","","","",""} ;
    while(getline(stream_place, word, ','))
    {
        place_cut[placeWordCnt] = word;
        placeWordCnt++;
    }
    
    int countAvailable = 0;
    int available[205] = {0} ;
    for(int i = 0 ; i <  budgetWordCnt ; i++)
    {
        for(int j = 0 ; j < 205 ; j++)
        {
            if(budget_cut[i] == all_Restaurant[j].budget)
            {
                for(int k = 0 ; k < typeWordCnt ; k++)
                {
                    if(all_Restaurant[j].type  == type_cut[k])
                    {
                        for(int u = 0; u < placeWordCnt; u++)
                        {
                            if(all_Restaurant[j].place == place_cut[u])
                            {
                                available[countAvailable] = j ;
                                countAvailable++;
                            }
                        }
                    }
                }
            }
        }
    }
    
    if(countAvailable == 0){
        return -1;
    }

    int ans = randomInt(countAvailable) ;
    return all_Restaurant[ans].index;
}

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
	  all_Restaurant[i].index = i;
	  i++;
	}    
}

int main()
{   
    string type;
    string budget;
    string place;
    cout << "�п�ܷQ�n���\\�U\����" << "\n";
    cout << "A1�G�t���BA2�G�ۧU�BA3�G�x���BA4�q���BA5�����BA6�䦡�BA7�馡�BA8�����BA9��L�]�p�I�ߡG���B���N�B�Q�p����) ����GA10���I�BA11�B�~�BA12����" << "\n";
    cin >> type; //�H�r�I�j�}
    cout << "�п�J���\\�w\��" << "\n";
    cout << "B1�]1��150�^�BB2�]151��250�^�BB3�]251��500�^�BB4�]501��infinity�^" << "\n";
    cin  >> budget; //�H�r�I�j�}
    cout << "�п�J�\\�U\�a�I" << "\n";
    cout << "C1�դ��BC2�s�ͫn�����BC3��������BC4�򶩸����BC5ù���ָ����BC6����������" << "\n";
    cin >> place; //�H�r�I�j�}
    
    
    
    restaurant all_Restaurant[1000];
    load_Csv("table.csv", all_Restaurant);
    
    int ansIndex = findAvailable(budget, type, place, all_Restaurant);
    if(ansIndex == -1){
        cout << "NO RESTAURANT";
    }
    else
        cout << all_Restaurant[ansIndex].name << "\n" << all_Restaurant[ansIndex].address <<endl;
    return 0;
}

// input an int n , return int from zero to n randomly
int randomInt(int countAvailable)
{
    random_device rd;
    
    /* ���˱���t��k */
    mt19937_64 generator( rd() );
    
    uniform_real_distribution< > dis(0 , countAvailable + 1) ;
    int x = dis(generator);
    return x;
}


#include <iostream>
//#define M 8

using namespace std;

class HashTable {
	private:
		int M;
		string** array;

	public:
		HashTable(int size)
		{
			M = size;
			*array = new string[M];
			for(int i=0; i<M; i++)
			{
				array[i]=NULL;
			}
		}
		int hashK(char* key)
		{
			int i=0;
			char c = key[i];
			int sum =0;
			while( c!= '\0')
			{
				sum += (int)c;
			 c = key[++i];   ////c equal to the key in next charactor
			}
			// int sum =0;
			// //key is pointer to the char
			// while( key[0] != '\0')
			// {
			// 	sum +=(int)key[0];
			// 	//cout<<"\tpreSize: "<<key<<"\tpostSize: "<< key + sizeof(char)<<endl;
			// 	key +=sizeof(char); //key pointer to the address
			// }
			//cout<<endl;
			return sum%M;
		}

		int insertKey(char* key,string* data)
		{
			int h = hashK(key); //find index
			if(h<0 || h>=8)
			{
				cout<<"Hash was invalided\n";
				return -1;
			}

			//find Collision
			if(array[h]!=NULL)
			{
				cout<<"Found a Collision\n";
				return -1;
			}
			else
			{
				array[h]=data;
				cout<<"Inserted: "<< *array[h]<<endl;
				return 0;
			}
		}

		string* search(char* key)
		{
			int h= hashK(key);
			return array[h];
		}
};


void search(string s)
    {
        //Compute the index by using the hash function
        int index = hashFunc(s);
        //Search the linked list at that specific index
        for(int i = 0;i < hashTable[index].size();i++)
        {
            if(hashTable[index][i] == s)
            {
                cout << s << " is found!" << endl;
                return;
            }
        }
        cout << s << " is not found!" << endl;
    }

    void insert(string s)
    {
                // Compute the index using Hash Function
        int index = hashFunc(s);
        // Insert the element in the linked list at the particular index
        hashTable[index].push_back(s);
    }



int main()
{
	//HashTable ht(8);
	// string data = "pepperorni";
	// ht.insertKey("topping", &data);
	// data = "sausage";
	// ht.insertKey("topping", &data);

	//char* key = '0';
	HashTable ht(8);
	char* key = new char;
	for(int i=0; i<8; i++)
	{
		*key = (char) i;
		cout<<"Hast("<<i<<")=" << ht.hashK(key) <<endl;
	}
	
	return 0;
}
// array.cpp by maxi
// date: 11.09.2013

#include <iostream>
#include <cstring>
#include <utility>
using namespace std;

class TArray
	{
	private:
		char array[256];
		int size_in;
	public:
		void getArray();
		void sortArray();
		void printArray();
		void finishArray();
		void replaceElement();
        void clean();
 	};

int main(void){
    TArray input;
    char choice;
    
    do{
        input.clean();
        
        cout << "Choose action - [E]nter, [S]ort, [R]eplace, [P]rint, e[X]it: ";
        cin >> choice;
        
        switch(choice){
            case 'E':
            case 'e':
                input.getArray();
                break;
            case 'S':
            case 's':
                input.sortArray();
                break;
            case 'R':
            case 'r':
                input.replaceElement();
                break;
            case 'P':
            case 'p':
                input.printArray();
                break;
            case 'X':
            case 'x':
                break;
            default:
                cout << "Error: command not found." << endl;
                break;
        }
	} while( choice != 'x' && choice != 'X' );
	return 0;
}
void TArray::getArray()
	{
        cout << "Enter array of symbols: ";
        cin >> array;
        size_in = strlen(array);
	}
		
void TArray::sortArray()
	{
        for(int i = 0; i < size_in; i++)
			for(int ii = 0; ii < size_in-1; ii++)
				if(array[ii] > array[ii+1])
					swap(array[ii+1], array[ii]);
	}
void TArray::printArray()
	{
		for(int i = 0; i < size_in; i++)
			cout << array[i] << ' ';
		cout << endl;
	}
void TArray::replaceElement()
	{
        int id;
        char value;
        cout << "Enter position of element to replace: "; cin >> id;
        cout << "Enter element: "; cin >> value;
        if(id >= 0 && id <= size_in)
            array[id-1] = value;
        else if(id > size_in)
            cout << "Error: ID is beyond the array!" << endl;
        else
            cout << "Error: ID should be positive." << endl;
	}
void TArray::clean()
    {
        array[size_in] = {0};
    }

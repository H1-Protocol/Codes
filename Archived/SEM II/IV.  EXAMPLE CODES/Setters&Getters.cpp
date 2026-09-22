 #include <iostream>
 #include <fstream>
using namespace std;



class Book{
    private:
    string title = "Title X";

    public:
string getTitle(){
        return title;
}

void setTitle(string title){
    this->title = title;
}
};

int main(){

    Book b1;
cout << "The Title of the Book is: " << b1.getTitle() << endl;
b1.setTitle("The Alchemist");
cout << endl << "Now, The Title of the Book is: " << b1.getTitle() << endl;


 return 0; 
}
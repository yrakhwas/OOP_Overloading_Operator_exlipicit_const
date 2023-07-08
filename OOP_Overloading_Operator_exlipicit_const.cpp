#include <iostream>
#include <vector>

using namespace std;

//class Date
//{
//    const int baseYear;
//    int& currentYear;
//    int day;
//    int month;
//    int year;
//
//public:
//    Date(int currYear) :baseYear(2000), currentYear(currYear) {}
//
//    void setDay(int value)
//    {
//        this->day = value;
//    }
//    int getDay()const
//    {
//        return day;
//    }
//};


class Account
{
    double sum;
    const double rate;
public:
    Account(double Rate, double Sum):rate(Rate)
    {
        //rate = Rate;
        sum = Sum;
    }
    double getRate()const
    {
        return rate;
    }
    double getIncome()
    {
        return sum / 100 * rate;
    }
    double getIncome()const
    {
        return sum / 100 * rate;
    }
    double getSum()const
    {
        return sum;
    }
    double getSum()
    {
        return sum;
    }
    double setSum()
    {
        sum -= getIncome();
        return sum;
    }
};

class Array
{
    int size;
    int* arr;
public:
    explicit Array(int size=10)
    {
        this->size = size;
        arr = new int[size];
    }
    explicit Array(const Array & other)
    {
        this->size = other.size;
        this->arr = new int[other.size];
        for (int i = 0; i < other.size; i++)
        {
            this->arr[i] = other.arr[i];
        }
    }
    int getSize()const
    {
        return size;
    }
    int getValue(int index)const
    {
        return arr[index];
    }
    void setValue(int num, int index)
    {
        arr[index] = num;
    }
    void display(int index)const
    {
        cout << arr[index] << " " << endl;
    }
    ~Array()
    {
        delete[]arr;
    }
};

void ShowArr(const Array& arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        arr.display(i);
    }
}

class Point
{
    int x;
    int y;
public:
    Point()
    {
        x = y = 0;
    }
    Point(int x, int y) :x(x), y(y) {}
    /*{
        this->x = x;
        this->y = y;
    }*/
    Point(const Point & other)
    {
        this->x = other.x;
        this->y = other.y;
    }
    void Show()const
    {
        cout << "X : " << x << " Y : " << y << endl;
    }
    Point Plus(const Point& other)
    {
        Point res(this->x + other.x, this->y + other.y);
        return res;
    }
    Point operator+(const Point& other)const
    {
        Point res(this->x + other.x, this->y + other.y);
        return res;
    }
    Point operator+(int value)const
    {
        Point res(this->x + value, this->y + value);
        return res;
    }
    bool operator >(const Point& p2)
    {
        return(this->x + this->y) > (p2.x + p2.y);
    }
    friend ostream& operator << (ostream& out, const Point& point);
    Point & operator --()
    {
        --x;
        --y;
        return *this;
    }
};
ostream& operator << (ostream& out, const Point& point)
{
    out << " X:" << point.x << " Y : " << point.y << endl;
    return out;
}

class Book
{
    string author;
    string name;
    string publishing;
    int year;
    int CountPages;
public:
    explicit Book(string author, string name, string publishing, int year, int countPages)
    {
        this->author = author;
        this->name = name;
        this->publishing = publishing;
        this->year = year;
        this->CountPages = countPages;
    }
    //explicit Book(){}
    string getAuthor()const
    {
        return author;
    }
    string getName()const
    {
        return name;
    }
    string getPublisher()const
    {
        return publishing;
    }
    int getYear()const
    {
        return year;
    }
    int getcountPages()const
    {
        return CountPages;
    }
    void ShowInfo()const
    {
        cout << "Name : " << name << endl;
        cout << "Author : " << author << endl;
        cout << "Publisher : " << publishing << endl;
        cout << "Year : " << year << endl;
        cout << "Count of Pages : " << CountPages << endl;
    }
};
Book AskInfo()
{
    string author;
    string name;
    string publishing;
    int year;
    int CountPages;
    cout << "Enter author : " << endl;
    cin >> author;
    cout << "Enter name : " << endl;
    cin >> name;
    cout << "Enter publisher : " << endl;
    cin >> publishing;
    cout << "Enter year : " << endl;
    cin >> year;
    cout << "Enter count of Pages : " << endl;
    cin >> CountPages;
     return Book(author, name, publishing, year, CountPages);
}
void returnAuthor(vector<Book> books, string name)
{
    for (const Book& book:books)
    {
        if (book.getAuthor() == name)
        {
            book.ShowInfo();
        }
    }
}
int main()
{
    vector<Book> books;


    //Book b1 = AskInfo();
    //Book b2 = AskInfo();
    //books.push_back(b2);
    //books.push_back(b1);
    books.push_back(Book("Author 2", "Book 2", "Publisher B", 2010, 250));
    books.push_back(Book("Author 1", "Book 3", "Publisher A", 2015, 400));
    books.push_back(Book("Author 3", "Book 4", "Publisher C", 2018, 150));
    string authorToSearch = "Author 2";
    //cout << " Enter author to find : " << endl;
    //cin >> authorToSearch;
    returnAuthor(books, authorToSearch);
    /*for (const Book &book:books)
    {
        if (book.getAuthor() == authorToSearch)
        {
            book.ShowInfo();
        }
    }*/


    //Point p1(1, 1);
    //Point p2(3, 4);
    //p1.Show();
    //p2.Show();
    //Point p3 = p1 + p2;
    //p3.Show();
    //Point p4 = p3 + 10;
    //p4.Show();
    //cout << p1;
    ////cout << p3 > p2 << endl;
    //cout << p4;
    //--p4;
    /*int a = 10;
    cout << a++ << endl;*/

    /*int a = 5, b = 10;
    int c = a + b;
    cout << c << endl;*/





    /*int size = 5;
    Array arr(size);
    for (int i = 0; i < size; i++)
    {
        arr.setValue(i, size - i - 1);
    }
    ShowArr(arr);*/
    //ShowArr(3);// неявне приведення
    //Array arr2 = 10;// неявне приведення




    //Account ac1(5, 2000);
    //const Account ac2(8, 5000);

    //cout << "Ac1 : " << ac1.getRate() << endl;
    //cout << "Ac2 : " << ac2.getRate() << endl;

    //cout << "Ac1 : " << ac1.getSum() << endl;
    //cout << "Ac2 : " << ac2.getSum() << endl;

    //cout << "Ac1 : " << ac1.getIncome() << endl;
    //cout << "Ac2 : " << ac2.getIncome() << endl;

    //cout << "Ac1 : " << ac1.setSum() << endl;
    ////cout << "Ac2 : " << ac2.setSum() << endl;

    //int a = 10.5;
    //cout << a << sizeof(a) << endl;


   /* Date adate(2000);
    adate.setDay(10);
    cout << adate.getDay() << endl;
    adate.setDay(20);
    cout << adate.getDay() << endl;*/

    
}

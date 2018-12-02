class animal
{
public:
    animal()
    {
        cout <<" animal():" <<this << endl;
    }
    void aaa()
    {
        eat();
    }

    void move()
    {
        cout << "animal move" << endl;
    }

    void eat()   //此处加virtual  结果就不一样了
    {
        cout << "animal eat" << endl;
    }
};


class dog:public animal
{
public:
    dog()
    {
        cout << "dog()    :" << this << endl;
    }

    void move()
    {
        cout << "dog move" << endl;
    }

    void eat()
    {
        cout << "dog eat" << endl;
    }
};

int main()
{
    dog d1;
    cout << &d1 << endl;
    d1.aaa();

    system("pause");
    return 0;
}
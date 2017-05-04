class k
{
public:
    k(int e):Eig(e)
    {}
};

// KLAUSURAUFGABE KONSTRUKTOR UND DESTRUCTOR AUFRUFE NACHVOLLZIEHEN
K*Obj;
Obj = new k(3); // konstruktor aufrufen
if(Obj)
{
    // do something
};
delete Obj;  // Destructor aufrufen
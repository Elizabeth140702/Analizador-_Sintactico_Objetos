#include <iostream>
#include <vector>

using namespace std;

class ElementoPila {
public:
    virtual void imprimir() = 0;
};

class Terminal : public ElementoPila {
private:
    string valor;
public:
    Terminal(string valor) {
        this->valor = valor;
    }
    void imprimir() {
        cout << valor << " (Terminal)" << endl;
    }
};

class NoTerminal : public ElementoPila {
private:
    string valor;
public:
    NoTerminal(string valor) {
        this->valor = valor;
    }
    void imprimir() {
        cout << valor << " (No Terminal)" << endl;
    }
};

class Estado : public ElementoPila {
private:
    string valor;
public:
    Estado(string valor) {
        this->valor = valor;
    }
    void imprimir() {
        cout << valor << " (Estado)" << endl;
    }
};

class Pila {
private:
    vector<ElementoPila*> elementos;
public:
    void push(ElementoPila* elemento) {
        elementos.push_back(elemento);
    }
    ElementoPila* pop() {
        if (elementos.empty()) {
            return nullptr;
        } else {
            ElementoPila* elemento = elementos.back();
            elementos.pop_back();
            return elemento;
        }
    }
    void imprimir() {
        for (ElementoPila* elemento : elementos) {
            elemento->imprimir();
        }
    }
};

int main() {
    Pila pila;
    pila.push(new Terminal("Maria Elizabeth Silva Baltazar"));
    pila.push(new NoTerminal("D02"));
    pila.push(new Estado("SSPTL2"));
    pila.imprimir();
    return 0;
}

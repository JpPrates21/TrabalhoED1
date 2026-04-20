#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Data {
    int dia, mes, ano;
    bool operator<(const Data& d) const {
        if (ano != d.ano) return ano < d.ano;
        if (mes != d.mes) return mes < d.mes;
        return dia < d.dia;
    }
};

struct Pessoa {
    string nome;
    Data datas[3];
    bool operator<(const Pessoa& p) const {
        return nome < p.nome;
    }
};

Data extrairData(string str) {
    Data d;
    d.dia = stoi(str.substr(0, 2));
    d.mes = stoi(str.substr(2, 2));
    int yy = stoi(str.substr(4, 2));
    d.ano = (yy <= 30) ? 2000 + yy : 1900 + yy; 
    return d;
}

int main() {
    ifstream arquivo("arquivo.txt");
    if (!arquivo.is_open()) {
        cout << "ERRO: O programa nao encontrou o arquivo.txt!" << endl;
        return 1;
    }

    vector<Pessoa> pessoas;
    string linha;

    while (getline(arquivo, linha)) {
        if (linha.length() <= 18) continue;

        Pessoa p;
        int corte = linha.length() - 18; 
        
        p.nome = linha.substr(0, corte);
        p.datas[0] = extrairData(linha.substr(corte, 6));
        p.datas[1] = extrairData(linha.substr(corte + 6, 6));
        p.datas[2] = extrairData(linha.substr(corte + 12, 6));

        sort(p.datas, p.datas + 3);
        pessoas.push_back(p);
    }
    arquivo.close();

    sort(pessoas.begin(), pessoas.end());

    for (const auto& p : pessoas) {
        cout << p.nome << " ";
        for (int i = 0; i < 3; ++i) {
            cout << p.datas[i].dia << "/" << p.datas[i].mes << "/" << p.datas[i].ano << " ";
        }
        cout << endl;
    }

    return 0;
}
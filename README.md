**Estudante:** João Pedro Pinheiro Prates  
**Curso:** Engenharia de Sistemas - UFMG  
**Disciplina:** Estruturas de Dados  


## 1. Estrutura de Dados
Para facilitar a gestão e comparação dos dados, foram implementadas as seguintes estruturas (`structs`):

* **`Data`**: Armazena o dia, mês e ano de forma separada como inteiros. Possui uma função de comparação (sobrecarga do operador `<`) que verifica a precedência do tempo (ano > mês > dia), permitindo a ordenação cronológica correta.
* **`Pessoa`**: Agrupa o nome do indivíduo e um conjunto fixo de três objetos do tipo `Data`. Inclui também uma lógica de comparação para permitir que a lista de pessoas seja ordenada alfabeticamente.

## 2. Lógica de Processamento

A execução do programa é dividida em quatro fases essenciais:

### 2.1. Leitura do Arquivo e Extração de Dados (Parsing)
O programa acede ao arquivo de texto e processa cada linha individualmente. Através do método de manipulação de strings (`substr`), o programa separa o nome das sequências numéricas. Como cada data possui 6 dígitos (DDMMYY) e existem 3 datas por pessoa, os últimos 18 caracteres de cada linha são sempre tratados como o bloco de datas, enquanto o restante da linha é identificado como o nome.

### 2.2. Normalização do Século
Dado que as datas no ficheiro original contêm apenas dois dígitos para o ano (YY), foi aplicada uma regra de conversão para garantir a precisão da ordenação entre séculos diferentes:
* Anos inferiores ou iguais a 30 são convertidos para o formato 20YY (ex: 25 -> 2025).
* Anos superiores a 30 são convertidos para o formato 19YY (ex: 99 -> 1999).

### 2.3. Algoritmo de Ordenação
O programa utiliza o algoritmo `std::sort` da biblioteca padrão em dois momentos distintos:
1.  **Ordenação Interna**: Ordena as três datas de cada pessoa individualmente logo após a sua extração.
2.  **Ordenação Global**: Ordena a lista completa de objetos `Pessoa` por ordem alfabética antes da fase de saída.

### 2.4. Exibição dos Resultados
Os dados são apresentados de forma simplificada, exibindo o nome seguido das suas respetivas datas já ordenadas. A formatação evita elementos visuais complexos para focar na clareza da informação processada.

# Projeto: Algoritmos de Ordenação

Projeto desenvolvido no 2º período do curso de Sistemas de Informação da UFOP (ICEA – João Monlevade), para a disciplina Algoritmos de ordenação 1.

Este projeto implementa e avalia o desempenho de diversos algoritmos de ordenação, permitindo testes com diferentes tamanhos e estados iniciais de vetores.

⚙️ Como compilar

Para compilar o projeto, abra o terminal no diretório raiz e utilize o comando abaixo:

gcc Algoritmos-de-Ordenacao/Principal/.c Algoritmos-de-Ordenacao/Ordena-vetores/.c Algoritmos-de-Ordenacao/Imprimir-vetores/*.c -I Algoritmos-de-Ordenacao/Ordena-vetores -I Algoritmos-de-Ordenacao/Imprimir-vetores -o ordenar

🚀 Como executar
Para rodar o código, utilize a linha de comando passando o nome do executável, o algoritmo escolhido, o tamanho do vetor e a flag de pré-visualização (opcional), seguindo esta estrutura:

./ordenar <algoritmo> <tamanho_do_vetor> [opções]

🧠 Algoritmos Disponíveis
Utilize as seguintes siglas para escolher o algoritmo de ordenação:

bub   - BubbleSort

bubo  - BubbleSort Otimizado

sel   - SelectionSort

selo  - SelectionSort Otimizado

ins   - InsertionSort

inso  - InsertionSort Otimizado

qui   - QuickSort

merge - MergeSort

heap  - HeapSort

📊 Tipos de Vetor (Estado Inicial)
ale   - Aleatório

ordc  - Ordenado (crescente)

ordi  - Desordenado (inversamente ordenado)

gord  - 1% Desordenado (quase ordenado)

🚩 Flags Adicionais
-p    - Pré-visualização: Imprime o vetor no terminal antes e depois da ordenação.

⚠️ Aviso: Não é obrigatório o uso desta flag. Tenha cuidado ao utilizá-la com valores altos de tamanho de vetor, pois o excesso de texto no console costuma congelar a IDE.

#include <string>
#include <iostream>

#include "Graph.hpp"
#include "memlog.h"

#define SUCCESS (00)
#define FAILURE (01)

char logName[100] = "data.out";

int main(int argc, char const *argv[])
{   
    // Inicialização do log de memória
    iniciaMemLog(logName);
    ativaMemLog();

    try
    {
        defineFaseMemLog(0);
        // Construção do grafo com os dados da entrada padrão
        Graph* graph = Graph::BuildFromIoStream();
        
        defineFaseMemLog(1);
        // Impressão se o grafo é "guloso" ou não
        bool isGreedy = graph->IsGreedy();
        std::cout << isGreedy;

        // Impressão dos vértices ordenados caso seja guloso
        if (isGreedy)
        {
            defineFaseMemLog(2);
            std::cout << " " << graph->OrderedVertices();
        }
            
        std::cout << std::endl;

        // Limpeza da memória alocada
        delete graph;

        finalizaMemLog();
    }
    catch(element_not_found_exception)
    {
        std::cout << "Houve uma tentativa inválida de acesso a um item da lista encadeada!" << std::endl;
        return FAILURE;
    }
    catch(invalid_orderer_option_exception)
    {
        std::cout << "O método de ordenação escolhido é inválido!" << std::endl;
        return FAILURE;
    }
    catch(unavailable_color_exception)
    {
        std::cout << "Coloração indisponível. Houve uma tentativa de atribuir uma cor indisponível a um vértice!" << std::endl;
        return FAILURE;
    }
    catch(invalid_color_change_exception)
    {
        std::cout << "Coloração inválida. Houve uma tentativa de atribuir uma cor fora do padrão a um vértice!" << std::endl;
        return FAILURE;
    }
    catch(...)
    {
        std::cout << "Houve um erro não identificado!" << std::endl;
        return FAILURE;
    }

    // Encerramento do código com sucesso
    return SUCCESS;
}
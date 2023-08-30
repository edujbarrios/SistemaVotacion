#include <iostream>
#include <vector>
#include <string>

/**
 * @class Candidato
 * @brief Representa a un candidato en una elección.
 */
class Candidato {
public:
    Candidato(const std::string& nombre) : nombre(nombre), votos(0) {}

    void recibirVoto() { ++votos; }

    int obtenerVotos() const { return votos; }

    std::string obtenerNombre() const { return nombre; }

private:
    std::string nombre;
    int votos;
};

/**
 * @class SistemaVotacion
 * @brief Gestiona el proceso de votación.
 */
class SistemaVotacion {
public:
    SistemaVotacion() {
        candidatos.emplace_back("Alice");
        candidatos.emplace_back("Bob");
        candidatos.emplace_back("Charlie");
    }

    void ejecutar() {
        std::string opcion;
        do {
            mostrarOpciones();
            std::cin >> opcion;
            procesarOpcion(opcion);
        } while (opcion != "FIN");
        mostrarResultados();
        mostrarGanador();
    }

private:
    std::vector<Candidato> candidatos;

    int totalVotos() const {
        int total = 0;
        for (const auto& candidato : candidatos) {
            total += candidato.obtenerVotos();
        }
        return total;
    }

    void mostrarOpciones() const {
        std::cout << "Candidatos disponibles para votar:\n";
        for (size_t i = 0; i < candidatos.size(); ++i) {
            std::cout << i + 1 << ". " << candidatos[i].obtenerNombre() << '\n';
        }
        std::cout << "Escriba el número del candidato o 'FIN' para finalizar: ";
    }

    void procesarOpcion(const std::string& opcion) {
        if (opcion == "FIN") {
            return;
        }
        int indice = std::stoi(opcion) - 1;
        if (indice >= 0 && indice < static_cast<int>(candidatos.size())) {
            candidatos[indice].recibirVoto();
        }
    }

    void mostrarResultados() const {
        int total = totalVotos();
        std::cout << "Resultados de la votación:\n";
        for (const auto& candidato : candidatos) {
            double porcentaje = (double)candidato.obtenerVotos() / total * 100;
            std::cout << candidato.obtenerNombre() << ": " << candidato.obtenerVotos() << " votos (" << porcentaje << "%)\n";
        }
    }

    void mostrarGanador() const {
        int maxVotos = 0;
        std::string nombreGanador;

        for (const auto& candidato : candidatos) {
            if (candidato.obtenerVotos() > maxVotos) {
                maxVotos = candidato.obtenerVotos();
                nombreGanador = candidato.obtenerNombre();
            }
        }

        std::cout << "El candidato ganador es: " << nombreGanador << " con " << maxVotos << " votos.\n";
    }
};

int main() {
    SistemaVotacion sistema;
    sistema.ejecutar();
    return 0;
}

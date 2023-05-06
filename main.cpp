#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int main() {
    int num_files;
    cout << "ingrese la cantidad de archivos a crear ";
    cin >> num_files;

    if (num_files % 2 == 0) { // si la cantidad es par
        fs::path par_folder = fs::path("C:/Users/cmarj/Documents/par/");
        if (!fs::exists(par_folder)) { // si la carpeta no existe, la creamos
            fs::create_directory(par_folder);
        }
        for (int i = 0; i < num_files; i++) {
            string filename = "file" + to_string(i+1) + ".txt";
            fs::path filepath = par_folder / filename;
            ofstream outfile(filepath);
            outfile << "Este es el archivo " << i+1 << " de " << num_files << ".";
            outfile.close();
        }
        cout << "Se han creado los archivos en la carpeta 'par' dentro de 'Documentos'." << endl;
    }
    else {
        fs::path desktop_folder = fs::path("C:/Users/cmarj/Desktop/");
        if (!fs::exists(desktop_folder)) {
            fs::create_directory(desktop_folder);
        }
        for (int i = 0; i < num_files; i++) {
            string filename = "file" + to_string(i+1) + ".txt";
            fs::path filepath = desktop_folder / filename;
            ofstream outfile(filepath);
            outfile << "Este es el archivo " << i+1 << " de " << num_files << ".";
            outfile.close();
        }
        cout << "Se han creado los archivos en el escritorio." << endl;
    }

    return 0;
}



#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int main() {
    int num_files;
    cout << "ingrese la cantidad de archivos a crear  ";
    cin >> num_files;

    if (num_files % 2 == 0) { // si la cantidad es par
        fs::path par_folder = fs::path("C:/Users/cmarj/Documents/par/");
        if (!fs::exists(par_folder)) {
            fs::create_directory(par_folder);
        }
        for (int i = 0; i < num_files; i++) {
            string filename = "file" + to_string(i+1) + ".txt";
            fs::path filepath = par_folder / filename;
            ofstream outfile(filepath);
            for (int j = 0; j < i+1; j++) {
                outfile << "Este es el archivo " << i+1 << " de " << num_files << ", línea " << j+1 << "." << endl;
            }
            outfile.close();
        }
        cout << "Se han creado los archivos en la carpeta 'par' dentro de 'Mis documentos'." << endl;
    }
    else {
        fs::path desktop_folder = fs::path("C:/Users/cmarj/Desktop/");
        for (int i = 0; i < num_files; i++) {
            string filename = "file" + to_string(i+1) + ".txt";
            fs::path filepath = desktop_folder / filename;
            ofstream outfile(filepath);
            for (int j = 0; j < i+1; j++) {
                outfile << "Este es el archivo " << i+1 << " de " << num_files << ", línea " << j+1 << "." << endl;
            }
            outfile.close();
        }
        cout << "Se han creado los archivos en el escritorio." << endl;
    }

    return 0;
}

#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

fs::path buscarArchivoMasGrande() {
    fs::path par_folder = fs::path("C:/Users/cmarj/Documents/par/");
    if (!fs::exists(par_folder)) {
        cout << "La carpeta 'par' no existe." << endl;
        return "";
    }

    fs::directory_iterator end_iter;
    fs::path archivo_mas_grande = "";
    uintmax_t tamano_mas_grande = 0;
    for (fs::directory_iterator iter(par_folder); iter != end_iter; ++iter) {
        if (fs::is_regular_file(iter->path())) {
            uintmax_t tamano_archivo = fs::file_size(iter->path());
            if (tamano_archivo > tamano_mas_grande) {
                tamano_mas_grande = tamano_archivo;
                archivo_mas_grande = iter->path();
            }
        }
    }

    if (archivo_mas_grande.empty()) {
        cout << "No se encontraron archivos regulares en la carpeta 'par'." << endl;
    }
    else {
        cout << "El archivo más grande es '" << archivo_mas_grande.filename() << "' con tamaño " << tamano_mas_grande << " bytes." << endl;
    }

    return archivo_mas_grande;
}

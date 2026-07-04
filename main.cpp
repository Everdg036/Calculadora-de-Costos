#include <iostream>
#include <iomanip> 
#include <limits>

using namespace std;

void calcularCostoImportacion() {

    cout << "\n========CALCULADORA DE COSTOS DE IMPORTACION======== \n";
    
    const double PRECIO_POR_LIBRA = 4.50;  // Costo de envío internacional 
    const double PORCENTAJE_ARANCEL = 0.10; // arancel aduanero
    const double PORCENTAJE_IVA = 0.16;    // IVA 
    const double SEGURO_ENVIO = 5.00;      // Costo fijo de seguro
    
    double costoBase = 0.0;
    double pesoLibras = 0.0;

    cout << "Ingrese el costo base del articulo (USD): $";
    while (!(cin >> costoBase) || costoBase < 0) {
        cout << "Error: Ingrese un monto valido y mayor o igual a 0: $";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    cout << "Ingrese el peso estimado del paquete (Libras): ";
    while (!(cin >> pesoLibras) || pesoLibras < 0) {
        cout << "Error: Ingrese un peso valido y mayor o igual a 0: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    double costoEnvio = pesoLibras * PRECIO_POR_LIBRA;
    double valorCif = costoBase + costoEnvio + SEGURO_ENVIO;
    
    double montoArancel = valorCif * PORCENTAJE_ARANCEL;
    double montoIva = (valorCif + montoArancel) * PORCENTAJE_IVA;
    
    double totalImpuestos = montoArancel + montoIva;
    double costoTotal = valorCif + totalImpuestos;
    
    cout << fixed << setprecision(2);
    
    cout << "========RESUMEN DE TU COTIZACION========        \n";
    cout << " Costo del articulo:       $" << costoBase << "\n";
    cout << " Costo de envio (" << pesoLibras << " lbs): $" << costoEnvio << "\n";
    cout << " Seguro y manejo:          $" << SEGURO_ENVIO << "\n";
    cout << "-----------------------------------------\n";
    cout << " Arancel aduanero (" << (PORCENTAJE_ARANCEL * 100) << "%):  $" << montoArancel << "\n";
    cout << " IVA (" << (PORCENTAJE_IVA * 100) << "%):              $" << montoIva << "\n";
    cout << "-----------------------------------------\n";
    cout << " TOTAL DE IMPUESTOS:       $" << totalImpuestos << "\n";
    cout << "=========================================\n";
    cout << " COSTO TOTAL PUESTO EN CASA: $" << costoTotal << "\n";
    cout << "=========================================\n\n";
}

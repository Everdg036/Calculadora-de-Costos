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
//
    double costoEnvio = pesoLibras * PRECIO_POR_LIBRA;
    double valorCif = costoBase + costoEnvio + SEGURO_ENVIO;
    
    double montoArancel = valorCif * PORCENTAJE_ARANCEL;
    double montoIva = (valorCif + montoArancel) * PORCENTAJE_IVA;
    
    double totalImpuestos = montoArancel + montoIva;
    double costoTotal = valorCif + totalImpuestos;
    
    cout << fixed << setprecision(2);

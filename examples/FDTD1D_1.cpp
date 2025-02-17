#include "1DBareBone.h"
#include "snapshot.h"

///============================================================================
/// Simple 1D FDTD simulation with a point source
///============================================================================
int main(int argc, char* argv[]) {
    const std::size_t Nx = 10000;
    const std::size_t Npml = 20;

    const double Lx = 0.10;
    const double CourantFactor = 0.99;
    const double tMax = 100e-12;
    const double fSrc = 30e9;
    const double sourcePosition = 0.05;

    std::string dataDir = "../data/FDTD1D_1"; // Default directory
    if (argc > 1) {
        dataDir = argv[1];
    }
    Snapshot<double> snapshot(dataDir);
    BareBone1D<double> simulation(Nx, 
                                  Npml, 
                                  Lx, 
                                  CourantFactor, 
                                  tMax, 
                                  fSrc, 
                                  sourcePosition, 
                                  snapshot);
    simulation.computeUpdateCoefficients();

    std::cout << "Running simulation..." << std::endl;
    simulation.runSimulation();
    std::cout << "Simulation completed." << std::endl;
    return 0;
}
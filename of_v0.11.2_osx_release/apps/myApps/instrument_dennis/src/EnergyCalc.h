
#pragma once

#include "ofxPDSPFunctions.h"

// FreqToPitch.h
// ofxPDSP
// Nicola Pisanti, MIT License, 2016

#include <AbsoluteValue.h>

#include "ofxFilterbank.h"
    /*!
    @brief Multiply in("signal") for in("mod").
    
    Multiply the in_signal() input for the in_mod() input. If the in_mod() input is running ad control rate and it is equal to 0, the in_signal() branch is not even calculated, saving cpu cycles.

    */
class EnergyCalc : public pdsp::Unit{
    
public:
    
    EnergyCalc();
    
    ~EnergyCalc();
    EnergyCalc(const EnergyCalc& other);
    EnergyCalc& operator=(const EnergyCalc& other);
                
    /*!
    @brief set the default  in("mod") value and returns the unit ready to be patched.
    @param[in] value Value to set for scaling the input signal, Default is 0.0f .
    */
    pdsp::AbsoluteValue val;
    /*!
    @brief Sets "signal" as selected input and returns this Unit ready to be patched. This is the default input. This input is the signal/value to multiply.
    */
    Patchable& in_signal();
    void setup ( ofxFilterbank * instance );

    /*!
    @brief Sets "mod" as selected input and returns this Unit ready to be patched. Value from in("signal") is multiplied by this value/signal. If the input is running at control rate and it is equal to 0.0f the signal branch is not processed. Defaulot value is 0.0f .
    */

    /*!
    @brief Sets "signal" as selected output and returns this Unit ready to be patched. This is the default output. This is the product of in("signal") multiplied by in("mod").
    */
    pdsp::Patchable& out_energy(const char * index);


    /*!
    @brief returns the value of the input buffer behind in("mod"), updated at control rate. This method is thread safe.
    */
    
    /*!
    @brief returns the value of the output buffer, updated at control rate. This method is thread safe.
    */
    float meter_output() const;
    
    
    pdsp::OutputNode outputEnergy0;
    pdsp::OutputNode outputEnergy1;
    pdsp::OutputNode outputEnergy2;
    pdsp::OutputNode outputEnergy3;
    pdsp::OutputNode outputEnergy4;
    pdsp::OutputNode outputEnergy5;
    pdsp::OutputNode outputEnergy6;
    pdsp::OutputNode outputEnergy7;
    pdsp::OutputNode outputEnergy8;
    pdsp::OutputNode outputEnergy9;
    pdsp::OutputNode outputEnergy10;
    pdsp::OutputNode outputEnergy11;

    ofxFilterbank * filterBank;


private:

    void prepareUnit ( int expectedBufferSize, double sampleRate ) override;
    
    void releaseResources () override;

    void process (int bufferSize) noexcept override;
    
    pdsp::InputNode input_signal;
    
    std::atomic<float> meter;
    std::atomic<float> meterOut;
    
};
        



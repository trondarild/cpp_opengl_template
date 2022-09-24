
#include <string>
#include <vector>
#include "tat_utils.h"

enum NeuronType {  eIntrinsically_bursting,eChattering,eFast_spiking,
  eLow_threshold,eResonator,eRegular_spiking};




class SpikingUnit {
public:
    int population_size=1;
  bool mdebug = false;
  float max_threshold = 65.0;
  int substeps;
  NeuronType neuronType;
  float tau_recovery;
  float coupling;
  float reset_voltage;
  float reset_recovery;
  float dir_current;
  float voltage;
  float recovery;
  FloatList* e_synapse;
  FloatList* i_synapse;
  std::string name;
  float noisefact = 0;
  
  //float[] vlt_buffer;
  // constructor
  SpikingUnit();
  SpikingUnit(std::string aname, NeuronType a_ntype,
              int a_substeps);
  //SpikingUnit(std:string aname, NeuronType a_ntype,
  //            int a_substeps, float noise);
  ~SpikingUnit();
  
  // accessors
  float getVlt();
  float getOutput();
  float getNormOutput();
  float getPhase();
  float getResetVoltage();
  float getTauRecovery();
  float getCoupling();
  float getResetRecovery();
  
  void setDirect(float current);
  void setDbg(bool on);
  void modulateResetVoltage(float val);
  void setResetVoltage(float val);
  void setNeuronType(NeuronType a_ntype);

  /** Randomization as per Izhikevich 2003
  */
  void randomize();
  
  void reset();
  
  void excite(float val);
  void inhibit(float val);
  
  
  
  void tick();
  
  // visualize
     
  FloatList timeStep_Iz(             float a_a, // tau recovery   //<>//
                                float a_b, // coupling
                                float a_c, // reset voltage
                                float a_d, // reset recovery    //<>//
                                FloatList *e_syn, // synapse - contains excitation and inh scaled by synaptic vals, or zero if not spiked    //<>//
                                FloatList *i_syn,   //<>//
                                float a_i, // direct current   //<>//
                                float a_v, // in out excitation
                                float a_u  // recovery  
                                );   
  
  
  void debug();
};
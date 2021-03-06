// 
// This class calculates the inclusive charged particle density
// in each for the 5 FMD rings based on the MC truth.
//
#ifndef ALIFMDMCDENSITYCALCULATOR_H
#define ALIFMDMCDENSITYCALCULATOR_H
/**
 * @file   AliFMDMCDensityCalculator.h
 * @author Christian Holm Christensen <cholm@dalsgaard.hehi.nbi.dk>
 * @date   Wed Mar 23 14:03:27 2011
 * 
 * @brief  
 * 
 * 
 * @ingroup pwglf_forward_aod
 */
#include "AliFMDDensityCalculator.h"
#include <TList.h>
#include "AliForwardUtil.h"
class AliMCEvent;
class TH2;
class TH2D;
class TProfile2D;

/** 
 * This class calculates the inclusive charged particle density
 * in each for the 5 FMD rings based on the MC truth.
 *
 * @par Input:
 *   - AliMCEvent  MC truth event infromation
 *
 * @par Output:
 *   - None
 *
 * @par Corrections used: 
 *   - None
 *
 * @ingroup pwglf_forward_algo
 * @ingroup pwglf_forward_mc
 * @ingroup pwglf_forward_aod
 */
class AliFMDMCDensityCalculator : public AliFMDDensityCalculator
{
public:
  /** 
   * Constructor 
   */
  AliFMDMCDensityCalculator() 
    : AliFMDDensityCalculator(),
      fFMD1i(0), 
      fFMD2i(0),
      fFMD2o(0),
      fFMD3i(0),
      fFMD3o(0),
      fFMD1iC(0), 
      fFMD2iC(0),
      fFMD2oC(0),
      fFMD3iC(0),
      fFMD3oC(0),
      fFMD1iD(0), 
      fFMD2iD(0),
      fFMD2oD(0),
      fFMD3iD(0),
      fFMD3oD(0),
      fComps(0)
  {}
  /** 
   * Constructor 
   * 
   * @param name Name of object
   */
  AliFMDMCDensityCalculator(const char* name) 
   : AliFMDDensityCalculator(name),
      fFMD1i(0), 
      fFMD2i(0),
      fFMD2o(0),
      fFMD3i(0),
      fFMD3o(0),
      fFMD1iC(0), 
      fFMD2iC(0),
      fFMD2oC(0),
      fFMD3iC(0),
      fFMD3oC(0),
      fFMD1iD(0), 
      fFMD2iD(0),
      fFMD2oD(0),
      fFMD3iD(0),
      fFMD3oD(0),
      fComps(0)
  {}
  /** 
   * Copy constructor 
   * 
   * @param o Object to copy from 
   */
  AliFMDMCDensityCalculator(const AliFMDMCDensityCalculator& o)
   : AliFMDDensityCalculator(o) ,
      fFMD1i(o.fFMD1i), 
      fFMD2i(o.fFMD2i),
      fFMD2o(o.fFMD2o),
      fFMD3i(o.fFMD3i),
      fFMD3o(o.fFMD3o),
      fFMD1iC(o.fFMD1iC), 
      fFMD2iC(o.fFMD2iC),
      fFMD2oC(o.fFMD2oC),
      fFMD3iC(o.fFMD3iC),
      fFMD3oC(o.fFMD3oC),
      fFMD1iD(o.fFMD1iD), 
      fFMD2iD(o.fFMD2iD),
      fFMD2oD(o.fFMD2oD),
      fFMD3iD(o.fFMD3iD),
      fFMD3oD(o.fFMD3oD),
      fComps(0)
  {}
  /** 
   * Destructor 
   */
  virtual ~AliFMDMCDensityCalculator();
  /** 
   * Assignement operator
   * 
   * @param o Object to assign from 
   * 
   * @return Reference to this object
   */
  AliFMDMCDensityCalculator& operator=(const AliFMDMCDensityCalculator& o);
  /** 
   * Initialize this object 
   * 
   * @param etaAxis Eta axis to use 
   */
  void SetupForData(const TAxis& etaAxis);
  /** 
   * Calculate the charged particle density from the MC track references. 
   * 
   * @param fmd    FMD ESD event structure
   * @param hists  Histograms to fill
   * 
   * @return true on success
   */
  virtual Bool_t CalculateMC(const AliESDFMD&        fmd,
			     AliForwardUtil::Histos& hists);
			     
  /** 
   * Compare the result of analysing the ESD for 
   * the inclusive charged particle density to analysing 
   * MC truth 
   * 
   * @param esd 
   * @param mc 
   * 
   * @return 
   */
  virtual Bool_t CompareResults(AliForwardUtil::Histos& esd, 
				AliForwardUtil::Histos& mc);
  /** 
   * Output diagnostic histograms to directory 
   * 
   * @param dir List to write in
   */  
  void CreateOutputObjects(TList* dir);
protected:
  /** 
   * MAke comparison profiles
   * 
   * @param d     Detector 
   * @param r     Ring 
   * @param axis  Eta axis 
   * 
   * @return Newly allocated profile object
   */
  TProfile2D* Make(UShort_t d, Char_t r, const TAxis& axis) const;
  /** 
   * MAke comparison profiles
   * 
   * @param d     Detector 
   * @param r     Ring 
   * 
   * @return Newly allocated profile object
   */
  TH2D* Make(UShort_t d, Char_t r) const;
  /** 
   * Make comparison profiles
   * 
   * @param d     Detector 
   * @param r     Ring 
   * @param max   Maximum 
   * 
   * @return Newly allocated profile object
   */
  TH1D* Make(UShort_t d, Char_t r, Int_t max) const;
  /** 
   * Fill comparison profiles
   * 
   * @param d    Detector 
   * @param r    Ring 
   * @param esd  ESD histogram
   * @param mc   MC histogram
   */
  void Fill(UShort_t d, Char_t r, TH2* esd, TH2* mc);

  TProfile2D* fFMD1i; // Comparison
  TProfile2D* fFMD2i; // Comparison
  TProfile2D* fFMD2o; // Comparison
  TProfile2D* fFMD3i; // Comparison
  TProfile2D* fFMD3o; // Comparison
  TH2D*       fFMD1iC; // Correlation in FMD1i
  TH2D*       fFMD2iC; // Correlation in FMD2i
  TH2D*       fFMD2oC; // Correlation in FMD2o
  TH2D*       fFMD3iC; // Correlation in FMD3i
  TH2D*       fFMD3oC; // Correlation in FMD3o
  TH1D*       fFMD1iD; // Correlation in FMD1i
  TH1D*       fFMD2iD; // Correlation in FMD2i
  TH1D*       fFMD2oD; // Correlation in FMD2o
  TH1D*       fFMD3iD; // Correlation in FMD3i
  TH1D*       fFMD3oD; // Correlation in FMD3o
  TList*      fComps; // List of comparisons 

  ClassDef(AliFMDMCDensityCalculator,2); // Calculate Nch density 
};

#endif
// Local Variables:
//   mode: C++
// End:


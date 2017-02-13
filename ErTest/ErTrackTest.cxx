#include "ErTrackTest.h"
#include <TMath.h>
#include <TRandom.h>
#include <TString.h>

/// \cond CLASSIMP
ClassImp(ErTrackTest);
/// \endcond

ErTrackTest::ErTrackTest() : ErVTrack() {
  ///
  /// A constructor
  ///
}

ErTrackTest::~ErTrackTest() {
  ///
  /// A destructor
  ///
}

void ErTrackTest::BuildRandom() {
  ///
  /// Building random event
  ///

  Double_t px, py;
  gRandom->Rannor(px, py);
  fPx = px;
  fPy = py;
  fPz = TMath::Sqrt(px * px + py * py);

  // Generate charge
  fCharge = (gRandom->Integer(2) > 0) ? 1 : -1;
}

void ErTrackTest::Print(Option_t * /*option*/) const {
  ///
  /// Printing track info
  ///

  Printf("ch=%d px=%.3f py=%.3f pz=%.3f", fCharge, fPx, fPy, fPz);
}

void ErTrackTest::Clear(Option_t *) {
  ///
  /// Reseting track to default values
  ///

  fCharge = 0;
  fPx = 0;
  fPy = 0;
  fPz = 0;
}

void ErTrackTest::SetP(Double_t *p) {
  ///
  /// Sets all components of momentum
  ///
  fPx = p[0];
  fPy = p[1];
  fPz = p[2];
}

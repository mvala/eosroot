#include "ErEventTest.h"
#include <TRandom.h>
#include <TString.h>

/// \cond CLASSIMP
ClassImp(ErEventTest);
/// \endcond

ErEventTest::ErEventTest() : ErVEvent(), fVx(0.0), fVy(0.0), fVz(0.0) {
  ///
  /// Default constructor
  ///
}

ErEventTest::ErEventTest(Long64_t id, Double_t vx, Double_t vy, Double_t vz)
    : ErVEvent(id), fVx(vx), fVy(vy), fVz(vz) {
  ///
  /// A constructor
  ///

  fTracks = new TClonesArray("ErTrackTest");
  gRandom->SetSeed(0);
}

ErEventTest::~ErEventTest() {
  ///
  /// A destructor
  ///

  delete fTracks;
  fTracks = 0;
}

ErTrackTest *ErEventTest::GetTrack(Long64_t id) {
  ///
  /// Return track with id
  ///
  return (ErTrackTest *)fTracks->At(id);
}

ErTrackTest *ErEventTest::AddTrack() {
  ///
  /// Adds track to event
  ///
  return (ErTrackTest *)fTracks->ConstructedAt(fNTracks++);
}
void ErEventTest::Print(Option_t *option) const {
  ///
  /// Printing event info
  ///
  Printf("id=%lld vx=%.3f vy=%.3f vz=%.3f", fID, fVx, fVy, fVz);

  if (!fTracks)
    return;

  TString str(option);
  str.ToLower();
  if (str.Contains("all")) {
    ErTrackTest *t;
    for (Int_t i = 0; i < fTracks->GetEntries(); i++) {
      t = (ErTrackTest *)fTracks->At(i);
      t->Print();
    }
  }
}

void ErEventTest::Clear(Option_t *) {
  ///
  /// Reseting event to default values and clear all tracks
  ///
  fID = 0;
  fVx = 0;
  fVy = 0;
  fVz = 0;

  fNTracks = 0;
  fTracks->Clear("C");
}

void ErEventTest::BuildVertexRandom() {
  ///
  /// Builds random vertex
  ///

  fVx = gRandom->Gaus();
  fVy = gRandom->Gaus();
  fVz = gRandom->Gaus();
}

#include "ErEvent.h"
#include <TRandom.h>
#include <TString.h>

/// \cond CLASSIMP
ClassImp(ErEvent);
/// \endcond

ErEvent::ErEvent()
    : TObject(), fID(0), fVx(0.0), fVy(0.0), fVz(0.0), fNTracks(0), fTracks(0) {
  ///
  /// Default constructor
  ///
}

ErEvent::ErEvent(Long64_t id, Double_t vx, Double_t vy, Double_t vz)
    : TObject(), fID(id), fVx(vx), fVy(vy), fVz(vz), fNTracks(0), fTracks(0) {
  ///
  /// A constructor
  ///

  fTracks = new TClonesArray("ErTrack");
  gRandom->SetSeed(0);
}

ErEvent::~ErEvent() {
  ///
  /// A destructor
  ///

  delete fTracks;
  fTracks = 0;
}

ErTrack *ErEvent::AddTrack() {
  ///
  /// Adds track to event
  ///
  return (ErTrack *)fTracks->ConstructedAt(fNTracks++);
}
void ErEvent::Print(Option_t *option) const {
  ///
  /// Printing event info
  ///
  Printf("id=%lld vx=%.3f vy=%.3f vz=%.3f", fID, fVx, fVy, fVz);

  if (!fTracks)
    return;

  TString str(option);
  str.ToLower();
  if (str.Contains("all")) {
    ErTrack *t;
    for (Int_t i = 0; i < fTracks->GetEntries(); i++) {
      t = (ErTrack *)fTracks->At(i);
      t->Print();
    }
  }
}

void ErEvent::Clear(Option_t *) {
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

void ErEvent::BuildVertexRandom() {
  ///
  /// Builds random vertex
  ///

  fVx = gRandom->Gaus();
  fVy = gRandom->Gaus();
  fVz = gRandom->Gaus();
}

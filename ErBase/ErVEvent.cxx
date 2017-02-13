#include "ErVEvent.h"
#include <TString.h>

/// \cond CLASSIMP
ClassImp(ErVEvent);
/// \endcond

ErVEvent::ErVEvent() : TObject(), fID(0), fNTracks(0), fTracks(0) {
  ///
  /// Default constructor
  ///
}

ErVEvent::ErVEvent(Long64_t id) : TObject(), fID(id), fNTracks(0), fTracks(0) {
  ///
  /// A constructor
  ///

  fTracks = new TClonesArray("ErVTrack");
}

ErVEvent::~ErVEvent() {
  ///
  /// A destructor
  ///

  delete fTracks;
  fTracks = 0;
}

ErVTrack *ErVEvent::GetTrack(Long64_t id) {
  ///
  /// Return track with id
  ///
  return (ErVTrack *)fTracks->At(id);
}

ErVTrack *ErVEvent::AddTrack() {
  ///
  /// Adds track to event
  ///
  return (ErVTrack *)fTracks->ConstructedAt(fNTracks++);
}
void ErVEvent::Print(Option_t *option) const {
  ///
  /// Printing event info
  ///
  Printf("id=%lld", fID);

  if (!fTracks)
    return;

  TString str(option);
  str.ToLower();
  if (str.Contains("all")) {
    ErVTrack *t;
    for (Int_t i = 0; i < fTracks->GetEntries(); i++) {
      t = (ErVTrack *)fTracks->At(i);
      t->Print();
    }
  }
}

void ErVEvent::Clear(Option_t *) {
  ///
  /// Reseting event to default values and clear all tracks
  ///
  fID = 0;

  fNTracks = 0;
  fTracks->Clear("C");
}

#ifndef ErEvent_cxx
#define ErEvent_cxx

#include "ErVTrack.h"
#include <TClonesArray.h>
#include <TObject.h>

///
/// \class ErVEvent
///
/// \brief Event object
///	\author Martin Vala <mvala@cern.ch>
///

class ErVEvent : public TObject {

public:
  ErVEvent();
  ErVEvent(Long64_t id);
  virtual ~ErVEvent();

  /// \fn Long64_t GetID() const
  /// Event ID
  /// \return event ID
  ///
  /// Sets event ID
  ///
  /// \fn void SetVx(Double_t vx)
  /// \param vx Input Vx
  ///
  /// \fn Long64_t GetNTrack() const
  /// \return number of tracks
  ///
  /// \fn ErVTrack *GetTrack(Long64_t id)
  /// \param id ID of track
  /// \return Track with id

  virtual Long64_t GetID() const { return fID; }

  virtual void SetID(Long64_t id) { fID = id; }

  virtual Long64_t GetNTrack() const { return fNTracks; }
  virtual ErVTrack *GetTrack(Long64_t id);
  virtual ErVTrack *AddTrack();

  virtual void Print(Option_t *option = "") const;
  virtual void Clear(Option_t *option = "");

  virtual void BuildRandom() = 0;

protected:
  Long64_t fID;   ///< ID of event
  Int_t fNTracks; ///< Number of tracks

  /// Array with all tracks
  TClonesArray *fTracks; //->

  // TODO
  /// Copy constructor
  ErVEvent(const ErVEvent &);            /// not implemented
  ErVEvent &operator=(const ErVEvent &); /// not implemented

  /// \cond CLASSIMP
  ClassDef(ErVEvent, 1);
  /// \endcond
};

#endif

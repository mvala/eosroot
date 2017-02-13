#ifndef ErEventTest_cxx
#define ErEventTest_cxx

#include "ErTrackTest.h"
#include <ErVEvent.h>
#include <TClonesArray.h>

///
/// \class ErEventTest
///
/// \brief Event object
///	\author Martin Vala <mvala@cern.ch>
///

class ErEventTest : public ErVEvent {

public:
  ErEventTest();
  ErEventTest(Long64_t id, Double_t vx = 0.0, Double_t vy = 0.0,
              Double_t vz = 0.0);
  virtual ~ErEventTest();

  /// \fn Long64_t GetID() const
  /// Event ID
  /// \return event ID
  ///
  /// \fn Double_t GetVx() const
  /// Vertex x component
  /// \return Vx component
  ///
  /// \fn Double_t GetVy() const
  /// Vertex y component
  /// \return Vy component
  ///
  /// \fn Double_t GetVz() const
  /// Vertex z component
  /// \return Vz component
  ///
  /// \fn void SetID(Long64_t id)
  /// \param id Input Evemt ID
  ///
  /// Sets event ID
  ///
  /// \fn void SetVx(Double_t vx)
  /// \param vx Input Vx
  ///
  /// Sets x component of vertex
  /// \fn void SetVy(Double_t vy)
  /// \param vy Input Vy
  ///
  /// Sets y component of vertex
  ///
  /// \fn void SetVz(Double_t vz)
  /// \param vz Input Vz
  ///
  /// Sets z component of vertex
  ///
  /// \fn Long64_t GetNTrack() const
  /// \return number of tracks
  ///
  /// \fn ErTrackTest *GetTrack(Long64_t id)
  /// \param id ID of track
  /// \return Track with id

  Double_t GetVx() const { return fVx; }
  Double_t GetVy() const { return fVy; }
  Double_t GetVz() const { return fVz; }

  void SetVx(Double_t vx) { fVx = vx; }
  void SetVy(Double_t vy) { fVy = vy; }
  void SetVz(Double_t vz) { fVz = vz; }

  virtual ErTrackTest *GetTrack(Long64_t id);
  virtual ErTrackTest *AddTrack();

  virtual void Print(Option_t *option = "") const;
  virtual void Clear(Option_t *option = "");

  void BuildVertexRandom();

private:
  Double_t fVx; ///< Vertex x
  Double_t fVy; ///< Vertex y
  Double_t fVz; ///< Vertex z

  // TODO
  /// Copy constructor
  ErEventTest(const ErEventTest &);            /// not implemented
  ErEventTest &operator=(const ErEventTest &); /// not implemented

  /// \cond CLASSIMP
  ClassDef(ErEventTest, 1);
  /// \endcond
};

#endif

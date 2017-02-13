#ifndef ErTrack_cxx
#define ErTrack_cxx

#include <TObject.h>

///
/// \class ErVTrack
///
/// \brief Track object
///	\author Martin Vala <mvala@cern.ch>
///

class ErVTrack : public TObject {

public:
  ErVTrack();
  virtual ~ErVTrack();
  virtual void Print(Option_t *option = "") const = 0;
  virtual void Clear(Option_t *option = "") = 0;

  virtual void BuildRandom() = 0;

protected:
  /// Copy constructor
  ErVTrack(const ErVTrack &);            /// not implemented
  ErVTrack &operator=(const ErVTrack &); /// not implemented

  /// \cond CLASSIMP
  ClassDef(ErVTrack, 1);
  /// \endcond
};

#endif

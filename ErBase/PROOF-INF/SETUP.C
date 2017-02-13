Int_t SETUP() {
  gSystem->Load("libErBase.so");
  if (!TClass::GetClass("ErEvent")) {
    return 1;
  }
  return 0;
}

Int_t SETUP() {
  gSystem->Load("libErTest.so");
  if (!TClass::GetClass("ErEventTest")) {
    return 1;
  }
  return 0;
}

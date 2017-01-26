
mkdir -p ../build
rm -rf ../build/*

pio ci --board=saml21_xpro_b --build-dir="../build" --keep-build-dir --lib="." examples/simple_read.cpp

#JFlashLite

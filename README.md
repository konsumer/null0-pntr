```
# configure for all
cmake -B build -G Ninja

# build native host
cmake --build build --target null0

# build a single cart
cmake --build build --target draw


# configre for web
emcmake cmake -B wbuild -G Ninja

# build web host
cmake --build wuild --target null0
```

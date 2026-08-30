# GameVerse Convention - COS 214 Practical 3

## Build
```bash
make
```

## Run
```bash
./eventflow
```

## Doxygen
```bash
doxygen Doxyfile
```

GameVerse is a gaming convention coordinated using the GoF Composite and Observer patterns. EventGroup is the Composite and is also an Observer/Subject so notices can cascade through nested areas. EventControl is the concrete Subject. EventUnit subclasses are concrete Leaves and Observers.

Observer references are non-owning. EventGroup owns children added through `add()`. `remove()` transfers ownership to the caller and updates observer registration, allowing safe runtime reorganisation.

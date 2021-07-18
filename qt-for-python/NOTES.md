# xml

- Code in xml needs some encoding &lt; &amp; etc. --> paniful to write --> we need some generator like sifipfy

# community support

- gitter very active and helpful
https://gitter.im/PySide/pyside2

- documentation

  - https://doc.qt.io/qtforpython/shiboken2/
  - https://doc.qt.io/qtforpython/shiboken2/typesystem.html
  - Concepts are well explained
  - Reference documentation for the typesystem not always up to date, best to check the sample code in tests instead
    - https://code.qt.io/cgit/pyside/pyside-setup.git/tree/sources/shiboken6/tests/samplebinding/typesystem_sample.xml

# Differences

> One of the goals of PySide6 is to be API compatible with PyQt, with certain exceptions.

See https://doc.qt.io/qtforpython/considerations.html

- Handwritten code is similar but different (what a surprise ... ;-) )
  - E.g. parameter with type `const QString &` (CPP) is available as `QString *` (SIP) and `const QString &` (PySide2)

# Compatibility layer? Deprecation?

- NULL (should this be replaced/aliased by None?)
- QVariant (PySide2 ignores it, should we try to build a compat layer?)
- Should we have some helpers/porters that modify imports and code instead?
- More an API improvement, but still: tuple (with boolean) return values instead of exceptions (e.g. stringToDistanceUnit())

# Thoughts about sipify V2

- Normalizing method signatures

# TODO

 - [ ] QgsRasterDataProvider -> is abstract and doesn't compile
 - [ ] QgsVectorLayer::dataProvider() -> is currently removed because problems with covariant return type. Non-issue according to gitter... Not sure what's wrong here.

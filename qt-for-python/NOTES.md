# Typesystem

Members are automatically detected, only enums need to be specifically mentioned in the typesystem file


# Differences

## Qt for Python vs PyQt/SIP

> One of the goals of PySide6 is to be API compatible with PyQt, with certain exceptions.

See https://doc.qt.io/qtforpython/considerations.html

- Handwritten code is similar but different (what a surprise ... ;-) )
  - E.g. parameter with type `const QString &` (CPP) is available as `QString *` (SIP) and `const QString &` (PySide2)

## Compatibility layer? Deprecation?

### NULL 
(should this be replaced/aliased by None?)

### QVariant 

As QVariant was removed, any function expecting it can receive any Python object (None is an invalid QVariant). The same rule is valid when returning something: the returned QVariant will be converted to its original Python object type.

When a method expects a QVariant::Type the programmer can use a string (the type name) or the type itself.
https://pyside.github.io/docs/pyside/pysideapi2.html#qvariant

Should we try to build a compat layer?
Should we have some helpers/porters that modify imports and code instead?

### QSignalSpy

QSignalSpy has just been added to Qt 6.1
https://wiki.qt.io/Qt_for_Python_Missing_Bindings

- More an API improvement, but still: tuple (with boolean) return values instead of exceptions (e.g. stringToDistanceUnit())

# Sipify

Like sip files, Qt-for-Python requires XML sidecar files.
We identify 3 ways to produce these files:

1) written by-hand, like it used to be some years ago with sip files
2) adapt sipify to produce them
3) re-write a similar tool based on clang-parser

- Code in xml needs some encoding &lt; &amp; etc. --> paniful to write --> we need some generator like sifipfy

- Normalizing method signatures

# Further considerations

## community support

- gitter very active and helpful
https://gitter.im/PySide/pyside2

## documentation

  - https://doc.qt.io/qtforpython/shiboken2/
  - https://doc.qt.io/qtforpython/shiboken2/typesystem.html
  - Concepts are well explained
  - Reference documentation for the typesystem not always up to date, best to check the sample code in tests instead
    - https://code.qt.io/cgit/pyside/pyside-setup.git/tree/sources/shiboken6/tests/samplebinding/typesystem_sample.xml

## QScintilla

QScintilla needs to be ported to PySide. The tool has been developped by Riverbank. 
TODO: check regarding license if we can do this.

# Translations

There is no corresponding tool for pylupdate with Qt for Python (see https://github.com/qgis/QGIS-Enhancement-Proposals/issues/163#issuecomment-804375040). 
Solution would be to either 
* rely on PyQt6
* add support for Python in the lupdate Qt tool
* build an ad-hoc tool using gettext which can mimic what lupdate is supposed to do


# TODO

 - [ ] QgsRasterDataProvider -> is abstract and doesn't compile
 - [ ] QgsVectorLayer::dataProvider() -> is currently removed because problems with covariant return type. Non-issue according to gitter... Not sure what's wrong here.


# Opportunities and risks to switch


# Estimation of the work load for a switch

# Moving on

If there is an interest to switch, we propose to proceed as follows:
1) PSC validates the financial engagmenent
2) The present report is published and we (the authors) collect feedback
3) PSC nominates a group of expert to formulate a decision (go/no-go)
4) PSC validates the decision


__all__ = ['core']

# Preload PySide2 libraries to avoid missing libraries while loading our module
try:
    from PySide2 import QtCore
except Exception:
    print("Failed to load PySide")
    raise

# Avoid duplicate namespace - the package name would normally look like this:
# PyKDDockWidgets.KDDockWidgets.KDDockWidgets.MainWindow
# (There is a bug PYSIDE-1325 to get this namespace duplication fixed.)
# To avoid this, we use this workaround:
# from .core import core as _priv

# core = _priv

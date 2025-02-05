Summary: Geoinformation Service Hybris Provider
URL: https://github.com/mer-hybris/geoclue-providers-hybris
License: LGPLv2
Source: %{name}-%{version}.tar.gz
BuildRequires: pkgconfig(Qt5Core)
BuildRequires: pkgconfig(Qt5DBus)
BuildRequires: pkgconfig(Qt5Network)
BuildRequires: pkgconfig(connman-qt5) >= 1.0.68
BuildRequires: pkgconfig(qofono-qt5)
BuildRequires: pkgconfig(qofonoext)
BuildRequires: pkgconfig(systemsettings) >= 0.5.5
BuildRequires: pkgconfig(systemd)
Requires: connectionagent-qt5 >= 0.9.20

Source100: geoclue-providers-hybris.inc

%description
%{summary}.

%prep
%autosetup -n %{name}-%{version}

%build
%{qmake_command}
%make_build

%install
%make_install

%files
%if 0%{?with_suid}
%defattr(04755,root,root,-)
%else
%defattr(-,root,root,-)
%endif
%license COPYING
%{_libexecdir}/geoclue-hybris
%defattr(-,root,root,-)
%{_sysconfdir}/dbus-1
%{_datadir}/dbus-1
%{_datadir}/geoclue-providers/geoclue-hybris.provider
%{_userunitdir}/geoclue-providers-hybris.service
%{_userunitdir}/dbus-org.freedesktop.Geoclue.Providers.Hybris.service

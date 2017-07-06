%define     __spec_install_post %{nil}
%define       debug_package %{nil}
%define     __os_install_post %{_dbpath}/brp-compress

Summary: MarkLogic C++ API client libraries
Name: mlclient
Version: %{_ver}
Release: 1
License: Apache 2.0
Group: Development/libraries
SOURCE0: %{name}-%{version}.tar.gz
URL: http://github.com/marklogic-community/mlcplusplus

BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root

%description
%{summary}

%prep
%setup -q

%build
# Empty

%install
rm -rf %{buildroot}
mkdir -p {buildroot}

# in builddir
cp -a * %{buildroot}

%clean
rm -rf %{buildroot}

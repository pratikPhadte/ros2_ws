from setuptools import find_packages
from setuptools import setup

setup(
    name='xrf2_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('xrf2_msgs', 'xrf2_msgs.*')),
)

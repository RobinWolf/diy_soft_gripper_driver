from setuptools import find_packages
from setuptools import setup

setup(
    name='gripper_interface',
    version='0.0.0',
    packages=find_packages(
        include=('gripper_interface', 'gripper_interface.*')),
)

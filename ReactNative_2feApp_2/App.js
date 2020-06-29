import React from 'react';
import { StyleSheet, Text, View, SafeAreaView, ScrollView, Dimensions, Image} from 'react-native';
import {Root, Fab} from 'native-base'
import {createDrawerNavigator, createAppContainer, DrawerItems} from 'react-navigation';
import { Font, AppLoading } from "expo";
import CouponsScreen from './screens/CouponsScreen';
import SettingsScreen from './screens/SettingsScreen';
import NewsScreen from './screens/NewsScreen';
import MyCouponsScreen from './screens/MyCouponsScreen';
import ProfileScreen from './screens/ProfileScreen';
import ContactsScreen from './screens/ContactsScreen';
import Icon from 'react-native-vector-icons/FontAwesome';

const { width } = Dimensions.get('window');

class App extends React.Component {

  state = {
    fontLoaded: false,
  }
  async componentWillMount() {
    await Font.loadAsync({
      Roboto: require("native-base/Fonts/Roboto.ttf"),
      Roboto_medium: require("native-base/Fonts/Roboto_medium.ttf")
    });
    this.setState({ loading: false });
  }

  render() {
    return (  
      <Root>
      <AppContainer />
      </Root>
    );
  }
}


const CustomDrawer = (props) => (

  <SafeAreaView style = {{flex: 1}}>


    <View style = {{height: 150, backgroundColor: 'white', alignItems: 'center', justifyContent: 'center'}}>
      <Image source = {require('./assets/logo.png')} style = {{width: 137, resizeMode: 'contain'}}/>
    </View>
    <ScrollView>
      <DrawerItems {...props} />  
    </ScrollView>

  </SafeAreaView>
);


const AppDrawerNavigator = createDrawerNavigator({
  Coupons: CouponsScreen,
  MyCoupons: MyCouponsScreen,
  News: NewsScreen,
  Settings: SettingsScreen,
  Profile: ProfileScreen,
  Contacts:ContactsScreen

}, {contentComponent: CustomDrawer, drawerWidth: width - width/2.5,
contentOptions: {
activeTintColor: "#5b6be8" 
},drawerType: 'slide'});




const AppContainer = createAppContainer(AppDrawerNavigator);

export default App;

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
});

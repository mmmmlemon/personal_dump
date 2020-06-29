import React from 'react';
import { StyleSheet, Text,  Image} from 'react-native';
import {Header, Left, Right, Button, Body} from  'native-base'
import Icon from 'react-native-vector-icons/FontAwesome';
import {withNavigation} from 'react-navigation';


class MyHeader extends React.Component {
  static navigationOptions = {
    drawerIcon: ({tintColor}) =>
        <Icon name = "cog" style = {{fontSize:24, color: tintColor}}/>
  }
  render() {
    return (
        <Header  style = {{height: 100, backgroundColor: "#5b6be8"}} hasTabs>
        <Left style = {{flex:1}}>
        <Button transparent onPress = {()=>this.props.navigation.openDrawer()}>
          <Icon name = "bars" style = {{fontSize: 30, color: 'white'}} />
        </Button>
        </Left>
        <Body style = {{flex:1}}>
         
        </Body>
        <Right style = {{flex:1}}>
        <Button transparent onPress = {()=>this.props.navigation.openDrawer()}>
          <Icon name = "map-marker" style = {{fontSize: 23, color: 'white'}} />
        </Button>
        <Button transparent onPress = {()=>this.props.navigation.navigate('Profile')}>
        <Text style = {{fontSize: 12, alignSelf: 'center', justifyContent: 'center', margin:6, color: "white"}}>Пользователь</Text>
            <Image  fadeDuration={0} source = {require('../assets/user.png')} style = {{width: 50, resizeMode: 'contain', borderRadius: 60}}/>
        </Button>
        </Right>
      </Header>
    );
  }
}

export default withNavigation(MyHeader);

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
});
